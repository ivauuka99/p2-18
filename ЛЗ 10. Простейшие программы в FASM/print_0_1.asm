name "print_0_1"
; ��������� �.�., 10.05.2020

org 100h

mov cx, 10          ; ����� ����������, ���� for
print: mov ah, 2    ; ������� ������
       mov dl, '0'  ; ������� '0'
       int 21h      ; ����� �������
       mov dl, '1'  ; ����� '1'
       int 21h      ; ����� �������
loop print
; ������� loop ��������� ��������� ����� ��������.
; ��������� �������� ��.
; ��������� �������� �� � �����:
;     ���� �� > 0, �� ���������� ���������� �� ����� ��������;
;     ���� �� = 0, �� ���������� ���������� �� ��������� ����� LOOP �������.

; �������� ������� �������
mov ah, 0
int 16h

ret
