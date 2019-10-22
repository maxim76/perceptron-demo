object Form1: TForm1
  Left = 393
  Top = 171
  Width = 479
  Height = 571
  Caption = 'Linear classifier Demo'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -10
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object Label4: TLabel
    Left = 336
    Top = 176
    Width = 32
    Height = 13
    Caption = 'Label4'
  end
  object pnlGrid: TPanel
    Left = 7
    Top = 98
    Width = 195
    Height = 195
    BevelOuter = bvLowered
    TabOrder = 0
  end
  object Panel1: TPanel
    Left = 7
    Top = 7
    Width = 195
    Height = 85
    BevelInner = bvLowered
    TabOrder = 1
    object Label1: TLabel
      Left = 13
      Top = 13
      Width = 28
      Height = 13
      Caption = 'Dim X'
    end
    object Label2: TLabel
      Left = 13
      Top = 39
      Width = 28
      Height = 13
      Caption = 'Dim Y'
    end
    object Label3: TLabel
      Left = 13
      Top = 65
      Width = 36
      Height = 13
      Caption = 'Classes'
    end
    object dimX: TCSpinEdit
      Left = 59
      Top = 7
      Width = 46
      Height = 22
      TabOrder = 0
    end
    object dimY: TCSpinEdit
      Left = 59
      Top = 33
      Width = 46
      Height = 22
      TabOrder = 1
    end
    object btReshape: TButton
      Left = 117
      Top = 25
      Width = 61
      Height = 20
      Caption = 'Reshape'
      TabOrder = 2
      OnClick = btReshapeClick
    end
    object dimClasses: TCSpinEdit
      Left = 59
      Top = 59
      Width = 46
      Height = 22
      TabOrder = 3
    end
    object btClear: TButton
      Left = 117
      Top = 57
      Width = 61
      Height = 20
      Caption = 'Clear'
      TabOrder = 4
      OnClick = btClearClick
    end
  end
  object sgClassList: TStringGrid
    Left = 7
    Top = 299
    Width = 195
    Height = 222
    ColCount = 2
    DefaultRowHeight = 18
    RowCount = 11
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 2
    ColWidths = (
      64
      167)
  end
  object btPredict: TBitBtn
    Left = 234
    Top = 98
    Width = 92
    Height = 20
    Caption = 'Predict'
    TabOrder = 3
  end
  object btTrain: TBitBtn
    Left = 234
    Top = 124
    Width = 92
    Height = 20
    Caption = 'Train/Correction'
    TabOrder = 4
  end
  object pnlDataSet: TPanel
    Left = 208
    Top = 232
    Width = 241
    Height = 289
    BevelInner = bvLowered
    TabOrder = 5
    object btDSAdd: TSpeedButton
      Left = 112
      Top = 40
      Width = 23
      Height = 22
      Hint = 'Add'
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00555555555555
        555555FFFFFFFFFF5F5557777777777505555777777777757F55555555555555
        055555555555FF5575F555555550055030555555555775F7F7F55555550FB000
        005555555575577777F5555550FB0BF0F05555555755755757F555550FBFBF0F
        B05555557F55557557F555550BFBF0FB005555557F55575577F555500FBFBFB0
        305555577F555557F7F5550E0BFBFB003055557575F55577F7F550EEE0BFB0B0
        305557FF575F5757F7F5000EEE0BFBF03055777FF575FFF7F7F50000EEE00000
        30557777FF577777F7F500000E05555BB05577777F75555777F5500000555550
        3055577777555557F7F555000555555999555577755555577755}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = btDSAddClick
    end
    object btDSDel: TSpeedButton
      Left = 136
      Top = 40
      Width = 23
      Height = 22
      Hint = 'Delete item'
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333333
        3333333333333333FF3333333333333003333333333333377F33333333333307
        733333FFF333337773333C003333307733333777FF333777FFFFC0CC03330770
        000077777FF377777777C033C03077FFFFF077FF77F777FFFFF7CC00000F7777
        777077777777777777773CCCCC00000000003777777777777777333330030FFF
        FFF03333F77F7F3FF3F7333C0C030F00F0F03337777F7F77373733C03C030FFF
        FFF03377F77F7F3F333733C03C030F0FFFF03377F7737F733FF733C000330FFF
        0000337777F37F3F7777333CCC330F0F0FF0333777337F737F37333333330FFF
        0F03333333337FFF7F7333333333000000333333333377777733}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = btDSDelClick
    end
    object btDSClear: TSpeedButton
      Left = 160
      Top = 40
      Width = 23
      Height = 22
      Hint = 'Clear DataSet'
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF0033333333B333
        333B33FF33337F3333F73BB3777BB7777BB3377FFFF77FFFF77333B000000000
        0B3333777777777777333330FFFFFFFF07333337F33333337F333330FFFFFFFF
        07333337F33333337F333330FFFFFFFF07333337F33333337F333330FFFFFFFF
        07333FF7F33333337FFFBBB0FFFFFFFF0BB37777F3333333777F3BB0FFFFFFFF
        0BBB3777F3333FFF77773330FFFF000003333337F333777773333330FFFF0FF0
        33333337F3337F37F3333330FFFF0F0B33333337F3337F77FF333330FFFF003B
        B3333337FFFF77377FF333B000000333BB33337777777F3377FF3BB3333BB333
        3BB33773333773333773B333333B3333333B7333333733333337}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = btDSClearClick
    end
    object btDSExport: TSpeedButton
      Left = 208
      Top = 40
      Width = 23
      Height = 22
      Hint = 'Export'
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000130B0000130B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333333333303
        333333333333337FF3333333333333903333333333333377FF33333333333399
        03333FFFFFFFFF777FF3000000999999903377777777777777FF0FFFF0999999
        99037F3337777777777F0FFFF099999999907F3FF777777777770F00F0999999
        99037F773777777777730FFFF099999990337F3FF777777777330F00FFFFF099
        03337F773333377773330FFFFFFFF09033337F3FF3FFF77733330F00F0000003
        33337F773777777333330FFFF0FF033333337F3FF7F3733333330F08F0F03333
        33337F7737F7333333330FFFF003333333337FFFF77333333333000000333333
        3333777777333333333333333333333333333333333333333333}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = btDSExportClick
    end
    object btDSShow: TSpeedButton
      Left = 184
      Top = 40
      Width = 23
      Height = 22
      Hint = 'Visualise'
      Glyph.Data = {
        76010000424D7601000000000000760000002800000020000000100000000100
        04000000000000010000120B0000120B00001000000000000000000000000000
        800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
        FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00337333733373
        3373337F3F7F3F7F3F7F33737373737373733F7F7F7F7F7F7F7F770000000000
        000077777777777777773303333333333333337FF333333F33333709333333C3
        333337773F3FF373F333330393993C3C33333F7F7F77F7F7FFFF77079797977C
        77777777777777777777330339339333C333337FF73373F37F33370C333C3933
        933337773F3737F37FF33303C3C33939C9333F7F7F7FF7F777FF7707C7C77797
        7C97777777777777777733033C3333333C33337F37F33333373F37033C333333
        33C3377F37333333337333033333333333333F7FFFFFFFFFFFFF770777777777
        7777777777777777777733333333333333333333333333333333}
      NumGlyphs = 2
      ParentShowHint = False
      ShowHint = True
      OnClick = btDSShowClick
    end
    object sgDataSet: TStringGrid
      Left = 2
      Top = 72
      Width = 237
      Height = 215
      Align = alBottom
      ColCount = 2
      DefaultRowHeight = 18
      FixedCols = 0
      RowCount = 1
      FixedRows = 0
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goColSizing, goRowSelect]
      TabOrder = 0
      ColWidths = (
        64
        108)
    end
    object StaticText1: TStaticText
      Left = 2
      Top = 2
      Width = 237
      Height = 28
      Align = alTop
      Alignment = taCenter
      Caption = 'DataSet'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -19
      Font.Name = 'MS Sans Serif'
      Font.Style = [fsBold]
      ParentFont = False
      TabOrder = 1
    end
    object cbClassList: TComboBox
      Left = 11
      Top = 42
      Width = 94
      Height = 21
      ItemHeight = 13
      TabOrder = 2
      Text = 'cbClassList'
      OnEnter = cbClassListEnter
    end
  end
end
