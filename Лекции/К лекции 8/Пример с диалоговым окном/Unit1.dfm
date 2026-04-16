object Form1: TForm1
  Left = 192
  Top = 107
  Width = 696
  Height = 480
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 64
    Top = 360
    Width = 32
    Height = 13
    Caption = 'Label1'
  end
  object Label2: TLabel
    Left = 16
    Top = 32
    Width = 32
    Height = 17
    Caption = 'Label2'
  end
  object Memo1: TMemo
    Left = 64
    Top = 96
    Width = 185
    Height = 217
    Lines.Strings = (
      'Memo1')
    TabOrder = 0
  end
  object Button1: TButton
    Left = 304
    Top = 240
    Width = 177
    Height = 25
    Caption = 'Button1'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 304
    Top = 280
    Width = 177
    Height = 25
    Caption = 'Button2'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 304
    Top = 104
    Width = 177
    Height = 25
    Caption = 'Button3'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 304
    Top = 144
    Width = 177
    Height = 25
    Caption = 'Button4'
    TabOrder = 4
    OnClick = Button4Click
  end
  object OpenDialog1: TOpenDialog
    Left = 416
    Top = 16
  end
  object SaveDialog1: TSaveDialog
    Left = 456
    Top = 16
  end
end
