name print_ab
; ��������� �.�., 11.05.2020
org 100h ; ��� .com

MOV AH, 02h  ; ������� ������
MOV DL, 41h  ; ASCII-��� ������� 'A'
INT 21h      ; ����� �������
MOV DL, 0Dh  ; chr(13), ������� �������
INT 21h      ; 
MOV DL, 0Ah  ; chr(10), ������� �� ����� ������
INT 21h      ; 
MOV DL, 'B'  ;
INT 21h      ;

ret
