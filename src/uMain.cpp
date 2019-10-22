//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "uMain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "CSPIN"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        gridSizeX = gridSizeY = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
    dimX->MaxValue = MAX_GRID_SIZE;
    dimY->MaxValue = MAX_GRID_SIZE;
    dimX->Text = IntToStr(DEFAULT_GRID_SIZE);
    dimY->Text = IntToStr(DEFAULT_GRID_SIZE);
    dimClasses->Text = IntToStr(DEFAULT_CLASS_COUNT);
    dimClasses->MaxValue = MAX_CLASS_COUNT;
    reshapeGrid(DEFAULT_GRID_SIZE, DEFAULT_GRID_SIZE);
    sgClassList->Cells[0][0] = "Class #";
    sgClassList->Cells[1][0] = "Class name";

}
//---------------------------------------------------------------------------
void __fastcall TForm1::GridCellClickHandler(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 if (((TShape *)Sender)->Tag == 0)
 {
    activateShape((TShape *)Sender);
 }
 else
 {
    deactivateShape((TShape *)Sender);
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GridCellMouseMoveHandler(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
  if ((((TShape *)Sender)->Tag == 0) && Shift.Contains(ssCtrl))
    activateShape((TShape *)Sender);
  if ((((TShape *)Sender)->Tag != 0) && Shift.Contains(ssAlt))
    deactivateShape((TShape *)Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::activateShape(TShape *shape)
{
    shape->Brush->Color = clRed;
    shape->Tag = 1;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::deactivateShape(TShape *shape)
{
    shape->Brush->Color = clWhite;
    shape->Tag = 0;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::btClearClick(TObject *Sender)
{
  TShape* pShape;
  for(int y=0; y<gridSizeY; y++)
      for(int x=0; x<gridSizeX; x++)
      {
        pShape = grid[x][y];
        deactivateShape(pShape);
      }
}
//---------------------------------------------------------------------------
void TForm1::reshapeGrid(int sizeX, int sizeY)
{
    // Delete old grid
    for(int x=0; x<gridSizeX; x++)
        for(int y=0; y<gridSizeY; y++)
            delete grid[x][y];
    // create new grid
    gridSizeX = sizeX;
    gridSizeY = sizeY;
    int potentialCellWidth = pnlGrid->Width / sizeX;
    int potentialCellHeight = pnlGrid->Height / sizeY;
    int cellSize = potentialCellWidth < potentialCellHeight ? potentialCellWidth : potentialCellHeight;
    for(int x=0; x<gridSizeX; x++)
        for(int y=0; y<gridSizeY; y++)
        {
            TShape *newShape = new TShape(pnlGrid);
            newShape->Left=x*cellSize;
            newShape->Top=y*cellSize;
            newShape->Height = cellSize;
            newShape->Width = cellSize;
            newShape->Parent = pnlGrid;
            newShape->Tag = 0;
            newShape->Visible = true;
            newShape->OnMouseDown = GridCellClickHandler;
            newShape->OnMouseMove = GridCellMouseMoveHandler;
            grid[x][y]=newShape;
        }
    classCount = StrToIntDef(dimClasses->Text, 0);
    sgClassList->RowCount = classCount + 1;
    for (int i=0; i<classCount;i++)
    {
        sgClassList->Cells[0][i+1] = IntToStr(i);
        sgClassList->Cells[1][i+1] = "";
    }
    replicateClasses();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btReshapeClick(TObject *Sender)
{
    if (MessageDlg("Data will be lost. Continue?",mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) == mrYes)
        reshapeGrid(StrToIntDef(dimX->Text, 0), StrToIntDef(dimY->Text,0));
}
//---------------------------------------------------------------------------
void TForm1::replicateClasses()
{
    TStringList *SL = new TStringList();
    for(int i=0; i<classCount; i++)
    {
        SL->Add(sgClassList->Cells[0][i+1] + " [" + sgClassList->Cells[1][i+1] + "]");
    }
    cbClassList->Items->Assign(SL);
    cbClassList->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::cbClassListEnter(TObject *Sender)
{
    replicateClasses();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::refreshDataSetList()
{
  int size = dataSet.size();
  sgDataSet->RowCount = size;
  for(int i=0; i<size; i++)
  {
    LabeledSample &labeledSample = dataSet[i];
    int classIndex = labeledSample.first;
    Sample &sample = labeledSample.second;
    AnsiString dump = "";
    for(unsigned int k=0; k<sample.size(); k++)
    {
      dump += IntToStr(sample[k]);
    }
    sgDataSet->Cells[0][i] = IntToStr(classIndex);
    sgDataSet->Cells[1][i] = dump;
  }
  // Bug workaround: StringGrid cannot have 0 rows. 1 rows always remains. Clear it manually
  if (size == 0)
  {
    sgDataSet->Cells[0][0] = "";
    sgDataSet->Cells[1][0] = "";
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btDSAddClick(TObject *Sender)
{
  Sample sample;
  TShape* pShape;
  int classIndex = cbClassList->ItemIndex;
  for(int y=0; y<gridSizeY; y++)
      for(int x=0; x<gridSizeX; x++)
      {
        pShape = grid[x][y];
        sample.push_back(pShape->Tag);
      }

  LabeledSample labeledSample(classIndex, sample);
  dataSet.push_back(labeledSample);
  refreshDataSetList();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btDSDelClick(TObject *Sender)
{
  if (dataSet.size()==0) return;
  int index = sgDataSet->Row;
  dataSet.erase(dataSet.begin() + index);
  refreshDataSetList();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btDSClearClick(TObject *Sender)
{
  if (MessageDlg("Clear all dataset?",mtConfirmation, TMsgDlgButtons() << mbYes << mbNo, 0) != mrYes)
        return;

  dataSet.clear();
  refreshDataSetList();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btDSShowClick(TObject *Sender)
{
  if (dataSet.size()==0) return;
  int index = sgDataSet->Row;
  LabeledSample &labeledSample = dataSet[index];
  int classIndex = labeledSample.first;
  Sample &sample = labeledSample.second;
  cbClassList->ItemIndex = classIndex;

  int size = sample.size();
  for(int i=0; i<size; i++)
  {
    if (sample[i])
      activateShape(grid[i % gridSizeX][i / gridSizeX]);
    else
      deactivateShape(grid[i % gridSizeX][i / gridSizeX]);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btDSExportClick(TObject *Sender)
{
  AnsiString FileName = "dataset.txt";
  int dsSize = dataSet.size();
  if (dsSize==0) return;
  FILE *f = fopen(FileName.c_str(), "w");
  if (!f)
  {
    ShowMessage( "Cannot create file " + FileName );
    return;
  }
  for(int i=0; i<dsSize;i++)
  {
    LabeledSample &labeledSample = dataSet[i];
    int classIndex = labeledSample.first;
    Sample &sample = labeledSample.second;
    AnsiString dump = "";
    for(unsigned int k=0; k<sample.size(); k++)
    {
      dump += IntToStr(sample[k]);
    }
    dump = IntToStr(classIndex) + ":" + dump;
    fprintf(f, "%s\n", dump.c_str());
  }
  fclose(f);
  ShowMessage("Exported into " + FileName);
}
//---------------------------------------------------------------------------

