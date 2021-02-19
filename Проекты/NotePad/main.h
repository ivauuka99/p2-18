//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Clipbrd.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <locale>

//---------------------------------------------------------------------------
class TNP : public TForm
{
__published:	// IDE-managed Components                                       //* - ������� � ������ ����
        TOpenDialog *OpenFile;                                                  //������ �������� ������
        TSaveDialog *SaveFile;                                                  //������ ���������� ������
        TFontDialog *Font;                                                      //������ �����
        TMainMenu *Trey;                                                        //���� ���������
        TMenuItem *File1;                                                       //*
        TMenuItem *Open;                                                        //*
        TMenuItem *Save;                                                        //*
        TMenuItem *Edit2;                                                       //*
        TMenuItem *Back;                                                        //*
        TMenuItem *Format;                                                      //*
        TMenuItem *WordWrap;                                                    //*
        TMenuItem *SaveAs;                                                      //*
        TMenuItem *see;                                                         //*
        TMenuItem *Scale;                                                       //*
        TMenuItem *Clear;                                                       //*
        TMenuItem *Copy;                                                        //*
        TMenuItem *Paste;                                                       //*
        TMenuItem *Del;                                                         //*
        TMenuItem *help;                                                        //*
        TMenuItem *About;                                                       //*
        TLabel *PosXY;                                                          //*
        TMenuItem *font1;                                                       //*
        TMenuItem *to_Enlarge;                                                  //*
        TMenuItem *Reduce;                                                      //*
        TMenuItem *Restore_default_scale;                                       //*
        TMenuItem *Status_bar;                                                  //*
        TLabel *Size_Font;                                                      //������ ������ � %
        TMemo *MText;                                                           //�������� ��������� ������
        TLabel *Way;                                                            //���������� ���� �����
        TMenuItem *Exit;                                                        //*
        TMenuItem *Find;                                                        //*
        TMenuItem *SelectAll;                                                   //*
        TFindDialog *FindD;                                                     //������� ������ � �����
        TReplaceDialog *ReplaceD;                                               //������� ������ � �����
        TMenuItem *Replace;                                                     //*
        TMenuItem *Find_Next;
        TStatusBar *StatusBar;                                                   //*
        void __fastcall OpenClick(TObject *Sender);                             //�������� �������� �������� ����
        void __fastcall DelClick(TObject *Sender);                              //������� ��������
        void __fastcall MTextChange(TObject *Sender);                           //������� ���������� �� �������� ������
        void __fastcall font1Click(TObject *Sender);                            //������� �����
        void __fastcall SaveClick(TObject *Sender);                             //������� ���������
        void __fastcall SaveAsClick(TObject *Sender);                           //������� ��������� ���
        void __fastcall WordWrapClick(TObject *Sender);                         //������� �������� ����
        void __fastcall TTEClose(TObject *Sender, TCloseAction &Action);        //������� �������� ����
        void __fastcall to_EnlargeClick(TObject *Sender);                       //������� ���������� ������
        void __fastcall ReduceClick(TObject *Sender);                           //������� ���������� ������
        void __fastcall Restore_default_scaleClick(TObject *Sender);            //������� �������������� ������� �����
        void __fastcall Status_barClick(TObject *Sender);                       //����������� ������ ����
        void __fastcall ExitClick(TObject *Sender);                             //������ ������
        void __fastcall CopyClick(TObject *Sender);                             //������ �����������
        void __fastcall PasteClick(TObject *Sender);                            //������ ��������
        void __fastcall ClearClick(TObject *Sender);                            //������ �������
        void __fastcall BackClick(TObject *Sender);                             //������ UNDO
        void __fastcall FormResize(TObject *Sender);                            //������� ��������� �����
        void __fastcall SelectAllClick(TObject *Sender);                        //������� ��������� �����
        void __fastcall FindClick(TObject *Sender);                             //������ ������
        void __fastcall FindDFind(TObject *Sender);                             //������� ������
        void __fastcall ReplaceDFind(TObject *Sender);                          //������� ������
        void __fastcall ReplaceDReplace(TObject *Sender);                       //������� ������ �����
        void __fastcall ReplaceClick(TObject *Sender);                          //������ ��������
        void __fastcall Find_NextClick(TObject *Sender);                        //������ ������ �����
        void __fastcall AboutClick(TObject *Sender);                            //������ � ���������
        void __fastcall MTextKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall MTextKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall StatusBarResize(TObject *Sender);
private:// User declarations
public:// User declarations
        __fastcall TNP(TComponent* Owner);
        int N, X, Y, FoundAt, StartPos, ToEnd;                                  //����������
        AnsiString FWay, FName, FileName, FPath, Xstr, Ystr;                    //
        String Str;                                                             //
        Boolean SaveF;                                                          //���������� ����������

};
//---------------------------------------------------------------------------
extern PACKAGE TNP *NP;
//---------------------------------------------------------------------------
#endif
