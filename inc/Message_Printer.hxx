// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Message_Printer_HeaderFile
#define _Message_Printer_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Message_Printer_HeaderFile
#include <Handle_Message_Printer.hxx>
#endif

#ifndef _MMgt_TShared_HeaderFile
#include <MMgt_TShared.hxx>
#endif
#ifndef _Message_Gravity_HeaderFile
#include <Message_Gravity.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Standard_CString_HeaderFile
#include <Standard_CString.hxx>
#endif
class TCollection_ExtendedString;
class TCollection_AsciiString;


//! Abstract interface class defining printer as output context for <br>
//!          text messages <br>
//! <br>
//!          The message, besides being text string, has associated gravity <br>
//!          level, which can be used by printer to decide either to process <br>
//!          a message or ignore it. <br>
class Message_Printer : public MMgt_TShared {

public:

  //! Send a string message with specified trace level. <br>
//!          The parameter putEndl specified whether end-of-line <br>
//!          should be added to the end of the message. <br>
//!          This method must be redefined in descentant. <br>
  Standard_EXPORT   virtual  void Send(const TCollection_ExtendedString& theString,const Message_Gravity theGravity,const Standard_Boolean putEndl) const = 0;
  //! Send a string message with specified trace level. <br>
//!          The parameter putEndl specified whether end-of-line <br>
//!          should be added to the end of the message. <br>
//!          Default implementation calls first method Send(). <br>
  Standard_EXPORT   virtual  void Send(const Standard_CString theString,const Message_Gravity theGravity,const Standard_Boolean putEndl) const;
  //! Send a string message with specified trace level. <br>
//!          The parameter putEndl specified whether end-of-line <br>
//!          should be added to the end of the message. <br>
//!          Default implementation calls first method Send(). <br>
  Standard_EXPORT   virtual  void Send(const TCollection_AsciiString& theString,const Message_Gravity theGravity,const Standard_Boolean putEndl) const;




  DEFINE_STANDARD_RTTI(Message_Printer)

protected:




private: 




};





// other Inline functions and methods (like "C++: function call" methods)


#endif