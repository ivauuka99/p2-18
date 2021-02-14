/*------------------------------------------------------------------------------
        ��������: ������� ����
        ������: �2-18
        ���: ��������� ���� ���������
//------------------------------------------------------------------------------
        � ���������:
������ ��������� ������� � C++ Builder 6, �������������� � ������� ��� ��.
��������� ������������ ����� ������������ ������ ����� ��������� �������� Windows,
�� �������� Microsoft, � ����� ������ �� ������������� ���������� �� ���������!

        �����������:
// - �������� �������� ��� �������
//** - ����� ����������� �������� �������� ��� �������
//*** - ����� ���������� �������� �������� ��� �������

        ������: 15 (������ OC 11.12.200a)

//----------------------------------------------------------------------------*/
#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "About.h"
//------------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTE *TE;
//--------------------�������� main �������-------------------------------------
__fastcall TTE::TTE(TComponent* Owner)
		: TForm(Owner)
{
	N = 100;                                                                //N - ������ ������ � %
	SaveF = false;                                                          //���������� false ��� ���������� �����
}
//-------------------������� ��������� ������� �����----------------------------
void __fastcall TTE::FormResize(TObject *Sender){
	TE->DoubleBuffered = true;                                              //�� ���� ������ ���, �� ��������� �������
	
	MText->Height=TE->Height/2;                                             //�� ���� ������ ���, �� ��������
	MText->Width=TE->Width/2;                                               //�� ���� ������ ���, �� ��������
}
//--------------------������� �����������---------------------------------------
void __fastcall TTE::CopyClick(TObject *Sender){
	MText->CopyToClipboard();                                               //�������� ���������� �����
	if(Clipboard()->HasFormat(CF_TEXT)){ Paste->Enabled = true; }           //��������� ���� �� ������������� �����
	   else{ Paste->Enabled = false; }                                      //���� ���, �� ��������� ��������
}
//-------------------������� ��������-------------------------------------------
void __fastcall TTE::PasteClick(TObject *Sender){
	MText->PasteFromClipboard();                                            //��������� ����� ������������� �����
}
//-------------------������� ��������-------------------------------------------
void __fastcall TTE::ClearClick(TObject *Sender){
	MText->CutToClipboard();                                                //������� MText(Memo1)
}
//-------------------������� ���������------------------------------------------
void __fastcall TTE::SelectAllClick(TObject *Sender){
	MText->SelectAll();                                                     //�������� ��
}
//-------------------������� ������(UNDO)---------------------------------------
void __fastcall TTE::BackClick(TObject *Sender){
	MText->Undo();                                                          //UNDO
}
//------------------������ �������� �����---------------------------------------
void __fastcall TTE::OpenClick(TObject *Sender){

        Paste->Enabled = false;                                                 //��������� ������ ��������
        Find_Next->Enabled = false;                                             //��������� ������ ����� �����

        //��������� ������ �� � �������� ��� �������� � ������ �� ������
	if(FName == "\0" && MText->Lines->Count > 0 && MessageDlg("�� ������ ��������� ������?",
		mtConfirmation  , TMsgDlgButtons() << mbNo << mbYes, 0) == mrYes && SaveFile->Execute()){
		
		MText->Lines->SaveToFile(SaveFile->FileName);
	}

	if (OpenFile->Execute()){                                               //�������� ���� �������� �����
		FWay = ExtractFileDir(OpenFile->FileName);                      //������ ���� �����
		FName = ExtractFileName(OpenFile->FileName);                    //������ �������� �����
		FPath = ExtractFilePath(OpenFile->FileName);                    //������ ���� ����� � /

		Caption = FName + " - �������";                                 //������ �������� �����
		
		MText->Lines->LoadFromFile(OpenFile->FileName);                 //������� ���������� � ����� � MText(Memo1)
		
		Way->Caption = FWay;                                            //������� � ������ ��� ����
		Save->Enabled = true;                                           //��������� ����������
		SaveF = false;                                                  //���������� �� ����
	}
}
//-----------------������ ��������/���������------------------------------------
void __fastcall TTE::DelClick(TObject *Sender){
	MText->ClearSelection();                                                //�������� ���������� �����
}
//------------------������� ������� �������-------------------------------------
void __fastcall TTE::MTextChange(TObject *Sender){
	Xstr = "|������ ";                                                      //X
	Ystr = ", ������� ";                                                    //Y
	X = MText->Perform(EM_LINEFROMCHAR, MText->SelStart, 0);                //���������� X
	Y = MText->SelStart - MText->Perform(EM_LINEINDEX, X, 0);               //���������� Y
		X += 1;                                                         //�� ���� ������ ���, �� ��� ��������
		Y += 1;                                                         //�� ���� ������ ���, �� ��� ��������
	PosXY->Caption = Xstr + X + Ystr + Y;                                   //����� � ������ ��� ���������� �� X � Y
}
//------------------������� ������ �����----------------------------------------
void __fastcall TTE::font1Click(TObject *Sender){
	if(Font->Execute()){MText->Font = Font->Font;}                          //��������� � ������� ���� �����, ����� �� ���� �����
}
//------------------������� ����������------------------------------------------
void __fastcall TTE::SaveClick(TObject *Sender){
	MText->Lines->SaveToFile(FPath+FName);                                  //���� ���� � ��� ����� � ����� ���������� ������ ��� �������� �����
	SaveF = true;                                                           //������ ��������� ���������� � true
}
//-----------------������� ��������� ���==--------------------------------------
void __fastcall TTE::SaveAsClick(TObject *Sender){
	if(SaveF == false && MText->Lines->Count > 0 && SaveFile->Execute()){   //�������� �� ����������, �� �� ������ ������ � ��������� ���������� ���� ����������
	   MText->Lines->SaveToFile(SaveFile->FileName);                        //��������� ���� ����� � ����

	   FWay = ExtractFileDir(SaveFile->FileName);                           //**
	   FName = ExtractFileName(SaveFile->FileName);                         //**
	   FPath = ExtractFilePath(SaveFile->FileName);                         //**
	   Caption = FName + " - �������";                                      //**

	   Way->Caption = FWay;                                                 //**
	   Save->Enabled = true;                                                //**
	   SaveF = true;                                                        //**
	}
}
//-------------------������ �������� ����---------------------------------------
void __fastcall TTE::WordWrapClick(TObject *Sender){
	TE->DoubleBuffered = true;                                              //**
	if(WordWrap->Checked == true){                                          //��������� ��������� ������
		MText->WordWrap = false;                                        //��������� ������� ������
		WordWrap->Checked = false;                                      //������ ���������� ������
		MText->ScrollBars = ssBoth;                                     //������ Scroll Bar � MText(Memo1)
	}else{                                                                  //���� if �� �����������, �� �������� ������� � ������� Scroll Bar
		MText->WordWrap = true;
		WordWrap->Checked = true;
		MText->ScrollBars = ssVertical;
	 }
}
//-----------------������ ���������� �����--------------------------------------
void __fastcall TTE::to_EnlargeClick(TObject *Sender){
	if (N < 500){                                                           //��������� ��������, ���� �� �� ���� ����� 500
		MText->Font->Size += 1;                                         //���������� 1 ������� � ���������
		Size_Font->Caption ="|" + IntToStr(N+=10) + "%";                //������� ���� � ��������� � %
	}
}
//-----------------������ ���������� ������-------------------------------------
void __fastcall TTE::ReduceClick(TObject *Sender){
	if (N > 10){                                                            //�������� ��������
		MText->Font->Size -= 1;                                         //�������� �������� ����� �� -1
		Size_Font->Caption ="|" + IntToStr(N-=10) + "%";                //������� ���� � ��������� � %
	}
}
//-----------------������ �������������� ������� ������-------------------------
void __fastcall TTE::Restore_default_scaleClick(TObject *Sender){
   MText->Font->Size = 12;                                                      //��������������� ������ ������
}
//-----------------������ ����������� ������� ����------------------------------
void __fastcall TTE::Status_barClick(TObject *Sender){
	if(Status_bar->Checked == true){                                        //��������� ������� �� ������
		PosXY->Visible = false;                                         //***��������� ������� ���
		Size_Font->Visible = false;                                     //***
		Status_bar->Checked = false;                                    //������ ������ �� ��������
		Way->Visible = false;                                           //***
		MText->Height = TE->Height - 60;                                //������� MText(Memo1) ����
	}else{
		PosXY->Visible = true;                                          //***�������� ������ ���
		Size_Font->Visible = true;                                      //***
		Status_bar->Checked = true;                                     //������ ������ ��������
		Way->Visible = true;                                            //***
		MText->Height = TE->Height - 75;                                //��������� MText(Memo1) �����
	 }
}
//----------------������ ������-------------------------------------------------
void __fastcall TTE::ExitClick(TObject *Sender){
	if(SaveF == true){                                                      //��������� �������� �� ����
		Close();                                                        //��������� ���������
	}else if(MText->Lines->Count > 0 && MessageDlg("�� ������ ��������� ��������� � ����� " + FPath + FName,
			mtConfirmation  , TMsgDlgButtons() << mbNo << mbYes, 0) == mrYes){
		MText->Lines->SaveToFile(FPath+FName);                          //��������� � �������� � ����������
		Application->Title = "�������";                                 //�������� �����
	 }


}
//--------------------������� ��� ������� �� ������ ��������--------------------
void __fastcall TTE::TTEClose(TObject *Sender, TCloseAction &Action){
	if(SaveF == false && FName == "\0" && MText->Lines->Count > 0 && MessageDlg("�� ������ ��������� ������?",
		mtConfirmation  , TMsgDlgButtons() << mbNo << mbYes, 0) == mrYes && SaveFile->Execute()){
		MText->Lines->SaveToFile(SaveFile->FileName);                   //***
	}else if(SaveF != true && FName != "\0" && MText->Lines->Count > 0 && MessageDlg("�� ������ ��������� ��������� � ����� " + FWay + "\\" + FName,
				mtConfirmation  , TMsgDlgButtons() << mbNo << mbYes, 0) == mrYes){
				MText->Lines->SaveToFile(FPath+FName);          //***
	 }
	SaveF = false;                                                          //***
}
//--------------------������ ������---------------------------------------------
void __fastcall TTE::FindClick(TObject *Sender)
{
	FindD->FindText = MText->SelText;                                       //�������� ���� �����
	FindD->Execute();                                                       //�������� � ������� FindDFind
}
//-------------------������� ������---------------------------------------------
void __fastcall TTE::FindDFind(TObject *Sender)
{
	StartPos = MText->SelStart;                                             //������� ������ ������ (��������� �������)
        Find_Next->Enabled = true;                                              //������ �������� ������ ������ �����

	if(MText->SelLength)                                                    //��������� ��� �������
		StartPos += MText->SelLength;                                   //��� �������� �������
		ToEnd = MText->Text.Length() - StartPos;                        //���� ����� ������

	if(FindD->Options.Contains(frMatchCase))                                //������� � ������ � ������
		FoundAt = StartPos + MText->Text.SubString(StartPos+1, ToEnd).Pos(FindD->FindText);

        //***
	else FoundAt = StartPos + MText->Text.SubString(StartPos+1, ToEnd).LowerCase().Pos(FindD->FindTextA.LowerCase());

	if(FoundAt != StartPos){                                                //***
		MText->SetFocus();                                              //������ ����� �� �������� ���� MText(Memo1)
		MText->SelStart = FoundAt-1;                                    //������� � �������� �������
		MText->SelLength = FindD->FindText.Length();                    //***
	}else ShowMessage("�� ������� ����� \""  + FindD->FindText + "\"");     //***
		Application->Title = "�������";                                 //***
}
//-----------------������� ������ ����------------------------------------------
void __fastcall TTE::ReplaceDFind(TObject *Sender)
{
	FoundAt = 0;                                                            //������� ������� � ������
	StartPos = MText->SelStart;                                             //***

	if(MText->SelStart)                                                     //***
			StartPos += MText->SelLength;                           //***
			ToEnd = MText->Text.Length() - StartPos;                //***

	if(FindD->Options.Contains(frMatchCase))                                //***
		FoundAt = StartPos + MText->Text.SubString(StartPos+1, ToEnd).Pos(ReplaceD->FindText);//***
	else FoundAt = StartPos + MText->Text.SubString(StartPos+1, ToEnd).LowerCase().Pos(ReplaceD->FindTextA.LowerCase());
		
	if(FoundAt != StartPos){                                                //***
		MText->SetFocus();                                              //***
		MText->SelStart = FoundAt-1;                                    //***
		MText->SelLength = ReplaceD->FindText.Length();                 //***
	}else{
		ShowMessage("�� ������� ����� \""  + ReplaceD->FindText + "\"");//***
		Application->Title = "�������";                                 //***
		MText->SetFocus();                                              //***
		MText->CaretPos = Point(0, 0);                                  //������� ������� �� 0 0
		return;
	 }
	 
	if(ReplaceD->Options.Contains(frReplaceAll))                            //� ������ ������� ������ �������� ��
		ReplaceDReplace(Sender);                                        //�������� ������� ReplaceDReplace
}
//--------------------������� ������ ALL----------------------------------------
void __fastcall TTE::ReplaceDReplace(TObject *Sender)
{
	if (MText->SelText != "")                                               //��������� ���� �� ���������� �����
			MText->SelText = ReplaceD->ReplaceTextA;                //***
	
	else if(ReplaceD->Options.Contains(frReplace)){                         //***
		ShowMessage("�� ������� �����\"" + ReplaceD->FindTextA +  "\"");//***
		Application->Title = "�������";                                 //***
		return;
	}

	if(ReplaceD->Options.Contains(frReplaceAll))                            //������������ � �������� �������
			ReplaceDFind(Sender);                                   //***
}
//------------------������ ������-----------------------------------------------
void __fastcall TTE::ReplaceClick(TObject *Sender)
{
	ReplaceD->FindTextA = MText->SelText;
	ReplaceD->Execute();
}
//------------------������ ������ �����-----------------------------------------
void __fastcall TTE::Find_NextClick(TObject *Sender)
{
        StartPos = MText->SelStart;                                             //***

	if(MText->SelLength)                                                    //***
		StartPos += MText->SelLength;                                   //***
		ToEnd = MText->Text.Length() - StartPos;                        //***

	if(FindD->Options.Contains(frMatchCase))
		FoundAt = StartPos + MText->Text.SubString(StartPos+1, ToEnd).Pos(FindD->FindText);//***

        //***
	else FoundAt = StartPos + MText->Text.SubString(StartPos+1, ToEnd).LowerCase().Pos(FindD->FindTextA.LowerCase());

	if(FoundAt != StartPos){                                                //***
		MText->SetFocus();                                              //***
		MText->SelStart = FoundAt-1;                                    //***
		MText->SelLength = FindD->FindText.Length();                    //***
	}else ShowMessage("�� ������� ����� \""  + FindD->FindText + "\"");     //***
		Application->Title = "�������";                                 //***
}
//------------------������ � ���������------------------------------------------

void __fastcall TTE::AboutClick(TObject *Sender)
{
        About_the_program->ShowModal();                                         //�������� ����� About_The_program
}
//------------------------------------------------------------------------------


