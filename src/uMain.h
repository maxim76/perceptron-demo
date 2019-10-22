//---------------------------------------------------------------------------

#ifndef uMainH
#define uMainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "CSPIN.h"
#include <Grids.hpp>
#include <Buttons.hpp>
#include <vector.h>
//---------------------------------------------------------------------------
#define MAX_GRID_SIZE   50
#define DEFAULT_GRID_SIZE   5
#define MAX_CLASS_COUNT     16
#define DEFAULT_CLASS_COUNT 10
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *pnlGrid;
    TPanel *Panel1;
    TLabel *Label1;
    TCSpinEdit *dimX;
    TCSpinEdit *dimY;
    TLabel *Label2;
    TButton *btReshape;
    TLabel *Label3;
    TCSpinEdit *dimClasses;
    TStringGrid *sgClassList;
    TBitBtn *btPredict;
    TBitBtn *btTrain;
        TPanel *pnlDataSet;
        TStringGrid *sgDataSet;
        TStaticText *StaticText1;
        TSpeedButton *btDSAdd;
        TSpeedButton *btDSDel;
        TSpeedButton *btDSClear;
        TSpeedButton *btDSExport;
        TComboBox *cbClassList;
        TSpeedButton *btDSShow;
        TButton *btClear;
        TLabel *Label4;
        void __fastcall GridCellClickHandler(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall GridCellMouseMoveHandler(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall FormCreate(TObject *Sender);
    void __fastcall btReshapeClick(TObject *Sender);
    void __fastcall cbClassListEnter(TObject *Sender);
        void __fastcall btDSAddClick(TObject *Sender);
        void __fastcall btDSDelClick(TObject *Sender);
        void __fastcall btDSClearClick(TObject *Sender);
        void __fastcall btDSShowClick(TObject *Sender);
        void __fastcall btDSExportClick(TObject *Sender);
        void __fastcall btClearClick(TObject *Sender);
private:	// User declarations
        void __fastcall refreshDataSetList();
        void __fastcall activateShape(TShape *);
        void __fastcall deactivateShape(TShape *);
public:		// User declarations
        typedef TShape* GridType;
        GridType grid[MAX_GRID_SIZE][MAX_GRID_SIZE];
        int gridSizeX, gridSizeY;
        int classCount;
        __fastcall TForm1(TComponent* Owner);
        void reshapeGrid(int, int);
        void replicateClasses();
        typedef vector<int> Sample;
        typedef pair< int, vector<int> > LabeledSample;
        //vector<Sample> dataSet;
        vector<LabeledSample> dataSet;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
