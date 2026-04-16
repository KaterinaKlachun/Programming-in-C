//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
//---------------------------------------------------------------------------
class TMyThreadClass : public TThread
{            
private:
        int index;
protected:
        void __fastcall Execute();
public:
        __fastcall TMyThreadClass(bool CreateSuspended);
        void __fastcall TMyThreadClass::UpdateCaption();
        TLabel *lstr;
};
//---------------------------------------------------------------------------
#endif
 