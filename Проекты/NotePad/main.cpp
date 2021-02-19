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
TNP *NP;
//--------------------�������� main �������-------------------------------------
__fastcall TNP::TNP(TComponent* Owner)
		: TForm(Owner)
{
        to_Enlarge->ShortCut = TextToShortCut("Ctrl+NUM +");
        Reduce->ShortCut = TextToShortCut("Ctrl+NUM -");
	N = 100;                                                                //N - ������ ������ � %
	SaveF = false;                                                          //���������� false ��� ���������� �����
}
//-------------------������� ��������� ������� �����----------------------------
void __fastcall TNP::FormResize(TObject *Sender){
	NP->DoubleBuffered = true;                                              //�� ���� ������ ���, �� ��������� �������
	
	MText->Height=NP->Height/2;                                             //�� ���� ������ ���, �� ��������
	MText->Width=NP->Width/2;                                               //�� ���� ������ ���, �� ��������
}
//--------------------������� �����������---------------------------------------
void __fastcall TNP::CopyClick(TObject *Sender){
	MText->CopyToClipboard();                                               //�������� ���������� �����
	if(Clipboard()->HasFormat(CF_TEXT)){ Paste->Enabled = true; }           //��������� ���� �� ������������� �����
	   else{ Paste->Enabled = false; }                                      //���� ���, �� ��������� ��������
}
//-------------------������� ��������-------------------------------------------
void __fastcall TNP::PasteClick(TObject *Sender){
	MText->PasteFromClipboard();                                            //��������� ����� ������������� �����
}
//-------------------������� ��������-------------------------------------------
void __fastcall TNP::ClearClick(TObject *Sender){
	MText->CutToClipboard();                                                //������� MText(Memo1)
}
//-------------------������� ���������------------------------------------------
void __fastcall TNP::SelectAllClick(TObject *Sender){
	MText->SelectAll();                                                     //�������� ��
}
//-------------------������� ������(UNDO)---------------------------------------
void __fastcall TNP::BackClick(TObject *Sender){
	MText->Undo();                                                          //UNDO
}
//------------------������ �������� �����---------------------------------------
void __fastcall TNP::OpenClick(TObject *Sender){

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

		StatusBar->Panels->Items[0]->Text = FWay;
		//Way->Caption = FWay;                                            //������� � ������ ��� ����
		Save->Enabled = true;                                           //��������� ����������
		SaveF = false;                                                  //���������� �� ����
	}
}
//-----------------������ ��������/���������------------------------------------
void __fastcall TNP::DelClick(TObject *Sender){
	MText->ClearSelection();                                                //�������� ���������� �����
}
//------------------������� ������� �������-------------------------------------
void __fastcall TNP::MTextChange(TObject *Sender){
	Xstr = "������ ";                                                      //X
	Ystr = ", ������� ";                                                    //Y
	X = MText->Perform(EM_LINEFROMCHAR, MText->SelStart, 0);                //���������� X
	Y = MText->SelStart - MText->Perform(EM_LINEINDEX, X, 0);               //���������� Y
		X += 1;                                                         //�� ���� ������ ���, �� ��� ��������
		Y += 1;                                                         //�� ���� ������ ���, �� ��� ��������
	//PosXY->Caption = Xstr + X + Ystr + Y;                                   //����� � ������ ��� ���������� �� X � Y
        StatusBar->Panels->Items[1]->Text = Xstr + X + Ystr + Y;
}
//------------------������� ������ �����----------------------------------------
void __fastcall TNP::font1Click(TObject *Sender){
	if(Font->Execute()){MText->Font = Font->Font;}                          //��������� � ������� ���� �����, ����� �� ���� �����
}
//------------------������� ����������------------------------------------------
void __fastcall TNP::SaveClick(TObject *Sender){
	MText->Lines->SaveToFile(FPath+FName);                                  //���� ���� � ��� ����� � ����� ���������� ������ ��� �������� �����
	SaveF = true;                                                           //������ ��������� ���������� � true
}
//-----------------������� ��������� ���==--------------------------------------
void __fastcall TNP::SaveAsClick(TObject *Sender){
	if(SaveF == false && MText->Lines->Count > 0 && SaveFile->Execute()){   //�������� �� ����������, �� �� ������ ������ � ��������� ���������� ���� ����������
	   MText->Lines->SaveToFile(SaveFile->FileName);                        //��������� ���� ����� � ����

	   FWay = ExtractFileDir(SaveFile->FileName);                           //**
	   FName = ExtractFileName(SaveFile->FileName);                         //**
	   FPath = ExtractFilePath(SaveFile->FileName);                         //**
	   Caption = FName + " - �������";                                      //**

           StatusBar->Panels->Items[0]->Text = FWay;
	  // Way->Caption = FWay;                                                 //**
	   Save->Enabled = true;                                                //**
	   SaveF = true;                                                        //**
	}
}
//-------------------������ �������� ����---------------------------------------
void __fastcall TNP::WordWrapClick(TObject *Sender){
	NP->DoubleBuffered = true;                                              //**
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
void __fastcall TNP::to_EnlargeClick(TObject *Sender){
	if (N < 500){                                                           //��������� ��������, ���� �� �� ���� ����� 500
		MText->Font->Size += 1;                                         //���������� 1 ������� � ���������
		//Size_Font->Caption ="|" + IntToStr(N+=10) + "%";                //������� ���� � ��������� � %
                StatusBar->Panels->Items[2]->Text = IntToStr(N+=10) + "%";
	}
}
//-----------------������ ���������� ������-------------------------------------
void __fastcall TNP::ReduceClick(TObject *Sender){
	if (N > 10){                                                            //�������� ��������
		MText->Font->Size -= 1;                                         //�������� �������� ����� �� -1
		//Size_Font->Caption ="|" + IntToStr(N-=10) + "%";                //������� ���� � ��������� � %
                StatusBar->Panels->Items[2]->Text = IntToStr(N-=10) + "%";
	}
}
//-----------------������ �������������� ������� ������-------------------------
void __fastcall TNP::Restore_default_scaleClick(TObject *Sender){
        N = 100;
        MText->Font->Size = 12;                                                      //��������������� ������ ������
        StatusBar->Panels->Items[2]->Text = "100%";
}
//-----------------������ ����������� ������� ����------------------------------
void __fastcall TNP::Status_barClick(TObject *Sender){
	if(Status_bar->Checked == true){                                        //��������� ������� �� ������
		//PosXY->Visible = false;                                         //***��������� ������� ���
		//Size_Font->Visible = false;                                     //***
                //Way->Visible = false;                                           //***
                StatusBar->Visible = false;
		Status_bar->Checked = false;                                    //������ ������ �� ��������
		MText->Height = NP->Height - 60;                                //������� MText(Memo1) ����
	}else{
		//PosXY->Visible = true;                                          //***�������� ������ ���
		//Size_Font->Visible = true;                                      //***
                //Way->Visible = true;                                            //***
                StatusBar->Visible = true;
		Status_bar->Checked = true;                                     //������ ������ ��������
		MText->Height = NP->Height - 75;                                //��������� MText(Memo1) �����
	 }
}
//----------------������ ������-------------------------------------------------
void __fastcall TNP::ExitClick(TObject *Sender){
	if(SaveF == true){                                                      //��������� �������� �� ����
		Close();                                                        //��������� ���������
	}else if(MText->Lines->Count > 0 && MessageDlg("�� ������ ��������� ��������� � ����� " + FPath + FName,
			mtConfirmation  , TMsgDlgButtons() << mbNo << mbYes, 0) == mrYes){
		MText->Lines->SaveToFile(FPath+FName);                          //��������� � �������� � ����������
		Application->Title = "�������";                                 //�������� �����
	 }


}
//--------------------������� ��� ������� �� ������ ��������--------------------
void __fastcall TNP::TTEClose(TObject *Sender, TCloseAction &Action){
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
void __fastcall TNP::FindClick(TObject *Sender){
	FindD->FindText = MText->SelText;                                       //�������� ���� �����
	FindD->Execute();                                                       //�������� � ������� FindDFind
}
//-------------------������� ������---------------------------------------------
void __fastcall TNP::FindDFind(TObject *Sender){
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
void __fastcall TNP::ReplaceDFind(TObject *Sender){
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
void __fastcall TNP::ReplaceDReplace(TObject *Sender){
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
void __fastcall TNP::ReplaceClick(TObject *Sender){
	ReplaceD->FindTextA = MText->SelText;
	ReplaceD->Execute();
}
//------------------������ ������ �����-----------------------------------------
void __fastcall TNP::Find_NextClick(TObject *Sender){
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
void __fastcall TNP::AboutClick(TObject *Sender){
        About_the_program->ShowModal();                                         //�������� ����� About_The_program
}
//------------------------------------------------------------------------------
void __fastcall TNP::MTextKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift){
        	Xstr = "������ ";                                               //X
	        Ystr = ", ������� ";                                            //Y
	X = MText->Perform(EM_LINEFROMCHAR, MText->SelStart, 0);                //���������� X
	Y = MText->SelStart - MText->Perform(EM_LINEINDEX, X, 0);               //���������� Y
		X += 1;                                                         //�� ���� ������ ���, �� ��� ��������
		Y += 1;                                                         //�� ���� ������ ���, �� ��� ��������
	//PosXY->Caption = Xstr + X + Ystr + Y;                                   //����� � ������ ��� ���������� �� X � Y
        StatusBar->Panels->Items[1]->Text = Xstr + X + Ystr + Y;
}
//---------------------------------------------------------------------------
void __fastcall TNP::MTextKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift){
        	Xstr = "������ ";                                               //X
	        Ystr = ", ������� ";                                            //Y
	X = MText->Perform(EM_LINEFROMCHAR, MText->SelStart, 0);                //���������� X
	Y = MText->SelStart - MText->Perform(EM_LINEINDEX, X, 0);               //���������� Y
		X += 1;                                                         //�� ���� ������ ���, �� ��� ��������
		Y += 1;                                                         //�� ���� ������ ���, �� ��� ��������
	//PosXY->Caption = Xstr + X + Ystr + Y;
        StatusBar->Panels->Items[1]->Text = Xstr + X + Ystr + Y;
}
//---------------------------------------------------------------------------

void __fastcall TNP::StatusBarResize(TObject *Sender)
{
    StatusBar->Panels->Items[0]->Width = NP->Width/2;
}
//---------------------------------------------------------------------------

