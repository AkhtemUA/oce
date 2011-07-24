// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _StepData_StepReaderData_HeaderFile
#define _StepData_StepReaderData_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_StepData_StepReaderData_HeaderFile
#include <Handle_StepData_StepReaderData.hxx>
#endif

#ifndef _TColStd_Array1OfInteger_HeaderFile
#include <TColStd_Array1OfInteger.hxx>
#endif
#ifndef _Interface_IndexedMapOfAsciiString_HeaderFile
#include <Interface_IndexedMapOfAsciiString.hxx>
#endif
#ifndef _TColStd_DataMapOfIntegerInteger_HeaderFile
#include <TColStd_DataMapOfIntegerInteger.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Handle_Interface_Check_HeaderFile
#include <Handle_Interface_Check.hxx>
#endif
#ifndef _Interface_FileReaderData_HeaderFile
#include <Interface_FileReaderData.hxx>
#endif
#ifndef _Standard_CString_HeaderFile
#include <Standard_CString.hxx>
#endif
#ifndef _Interface_ParamType_HeaderFile
#include <Interface_ParamType.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Handle_StepData_PDescr_HeaderFile
#include <Handle_StepData_PDescr.hxx>
#endif
#ifndef _Handle_Standard_Transient_HeaderFile
#include <Handle_Standard_Transient.hxx>
#endif
#ifndef _Handle_StepData_SelectMember_HeaderFile
#include <Handle_StepData_SelectMember.hxx>
#endif
#ifndef _Handle_StepData_ESDescr_HeaderFile
#include <Handle_StepData_ESDescr.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Handle_Standard_Type_HeaderFile
#include <Handle_Standard_Type.hxx>
#endif
#ifndef _StepData_Logical_HeaderFile
#include <StepData_Logical.hxx>
#endif
#ifndef _Handle_TCollection_HAsciiString_HeaderFile
#include <Handle_TCollection_HAsciiString.hxx>
#endif
class Interface_Check;
class TCollection_AsciiString;
class TColStd_SequenceOfAsciiString;
class StepData_PDescr;
class Standard_Transient;
class StepData_SelectMember;
class StepData_Field;
class StepData_ESDescr;
class StepData_FieldList;
class Standard_Type;
class StepData_SelectType;
class TCollection_HAsciiString;
class StepData_EnumTool;


//! Specific FileReaderData for Step <br>
//!           Contains litteral description of entities (for each one : type <br>
//!           as a string, ident, parameter list) <br>
//!           provides references evaluation, plus access to litteral data <br>
//!           and specific access methods (Boolean, XY, XYZ) <br>
class StepData_StepReaderData : public Interface_FileReaderData {

public:

  //! creates StepReaderData correctly dimensionned (necessary at <br>
//!           creation time, because it contains arrays) <br>
//!           nbheader is nb of records for Header, nbtotal for Header+Data <br>
//!           and nbpar gives the total count of parameters <br>
  Standard_EXPORT   StepData_StepReaderData(const Standard_Integer nbheader,const Standard_Integer nbtotal,const Standard_Integer nbpar);
  //! Fills the fields of a record <br>
  Standard_EXPORT     void SetRecord(const Standard_Integer num,const Standard_CString ident,const Standard_CString type,const Standard_Integer nbpar) ;
  //! Fills the fields of a parameter of a record. This is a variant <br>
//!           of AddParam, Adapted to STEP (optimized for specific values) <br>
  Standard_EXPORT     void AddStepParam(const Standard_Integer num,const Standard_CString aval,const Interface_ParamType atype,const Standard_Integer nument = 0) ;
  //! Returns Record Type <br>
  Standard_EXPORT    const TCollection_AsciiString& RecordType(const Standard_Integer num) const;
  //! Returns Record Type as a CString <br>
//! was C++ : return const <br>
  Standard_EXPORT     Standard_CString CType(const Standard_Integer num) const;
  //! Returns record identifier (Positive number) <br>
//!           If returned ident is not positive : Sub-List or Scope mark <br>
  Standard_EXPORT     Standard_Integer RecordIdent(const Standard_Integer num) const;
  //! Returns SubList numero designated by a parameter (nump) in a <br>
//!           record (num), or zero if the parameter does not exist or is <br>
//!           not a SubList address. Zero too If aslast is True and nump <br>
//!           is not for the last parameter <br>
  Standard_EXPORT     Standard_Integer SubListNumber(const Standard_Integer num,const Standard_Integer nump,const Standard_Boolean aslast) const;
  //! Returns True if <num> corresponds to a Complex Type Entity <br>
//!           (as can be defined by ANDOR Express clause) <br>
  Standard_EXPORT     Standard_Boolean IsComplex(const Standard_Integer num) const;
  //! Returns the List of Types which correspond to a Complex Type <br>
//!           Entity. If not Complex, there is just one Type in it <br>
//!           For a SubList or a Scope mark, <types> remains empty <br>
  Standard_EXPORT     void ComplexType(const Standard_Integer num,TColStd_SequenceOfAsciiString& types) const;
  //! Returns the Next "Componant" for a Complex Type Entity, of <br>
//!           which <num> is already a Componant (the first one or a next one) <br>
//!           Returns 0 for a Simple Type or for the last Componant <br>
  Standard_EXPORT     Standard_Integer NextForComplex(const Standard_Integer num) const;
  //! Determines the first component which brings a given name, for <br>
//!           a Complex Type Entity <br>
//!           <num0> is the very first record of this entity <br>
//!           <num> is given the last NextNamedForComplex, starts at zero <br>
//!           it is returned as the newly found number <br>
//!           Hence, in the normal case, NextNamedForComplex starts by num0 <br>
//!           if <num> is zero, else by NextForComplex(num) <br>
//!           If the alphabetic order is not respected, it restarts from <br>
//!           num0 and loops on NextForComplex until finding <name> <br>
//!           In case of "non-alphabetic order", <ach> is filled with a <br>
//!             Warning for this name <br>
//!           In case of "not-found at all", <ach> is filled with a Fail, <br>
//!             and <num> is returned as zero <br>
//! <br>
//!           Returns True if alphabetic order, False else <br>
  Standard_EXPORT     Standard_Boolean NamedForComplex(const Standard_CString name,const Standard_Integer num0,Standard_Integer& num,Handle(Interface_Check)& ach) const;
  //! Checks Count of Parameters of record <num> to equate <nbreq> <br>
//!           If this Check is successful, returns True <br>
//!           Else, fills <ach> with an Error Message then returns False <br>
//!           <mess> is included in the Error message if given non empty <br>
  Standard_EXPORT     Standard_Boolean CheckNbParams(const Standard_Integer num,const Standard_Integer nbreq,Handle(Interface_Check)& ach,const Standard_CString mess = "") const;
  //! reads parameter <nump> of record <num> as a sub-list (may be <br>
//!           typed, see ReadTypedParameter in this case) <br>
//!           Returns True if OK. Else (not a LIST), returns false and <br>
//!           feeds Check with appropriate check <br>
//!           If <optional> is True and Param is not defined, returns True <br>
//!             with <ach> not filled and <numsub> returned as 0 <br>
//!           Works with SubListNumber with <aslast> false (no specific case <br>
//!           for last parameter) <br>
  Standard_EXPORT     Standard_Boolean ReadSubList(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach,Standard_Integer& numsub,const Standard_Boolean optional = Standard_False,const Standard_Integer lenmin = 0,const Standard_Integer lenmax = 0) const;
  //! reads the content of a sub-list into a transient : <br>
//!           SelectNamed, or HArray1 of Integer,Real,String,Transient ... <br>
//!           recursive call if list of list ... <br>
//!           If a sub-list has mixed types, an HArray1OfTransient is <br>
//!             produced, it may contain SelectMember <br>
//!           Intended to be called by ReadField <br>
//!           The returned status is : negative if failed, 0 if empty. <br>
//!           Else the kind to be recorded in the field <br>
  Standard_EXPORT     Standard_Integer ReadSub(const Standard_Integer numsub,const Standard_CString mess,Handle(Interface_Check)& ach,const Handle(StepData_PDescr)& descr,Handle(Standard_Transient)& val) const;
  //! Reads parameter <nump> of record <num> into a SelectMember, <br>
//!           self-sufficient (no Description needed) <br>
//!           If <val> is already created, it will be filled, as possible <br>
//!           And if reading does not match its own description, the result <br>
//!           will be False <br>
//!           If <val> is not it not yet created, it will be (SelectNamed) <br>
//!           Usefull if a field is defined as a SelectMember, directly <br>
//!           (SELECT with no Entity as member) <br>
//!           But SelectType also manages SelectMember (for SELECT with <br>
//!           some members as Entity, some other not) <br>
  Standard_EXPORT     Standard_Boolean ReadMember(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach,Handle(StepData_SelectMember)& val) const;
  //! reads parameter <nump> of record <num> into a Field, <br>
//!           controlled by a Parameter Descriptor (PDescr), which controls <br>
//!           its allowed type(s) and value <br>
//!           <ach> is filled if the read parameter does not match its <br>
//!           description (but the field is read anyway) <br>
//!           If the description is not defined, no control is done <br>
//!           Returns True when done <br>
  Standard_EXPORT     Standard_Boolean ReadField(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach,const Handle(StepData_PDescr)& descr,StepData_Field& fild) const;
  //! reads a list of fields controlled by an ESDescr <br>
  Standard_EXPORT     Standard_Boolean ReadList(const Standard_Integer num,Handle(Interface_Check)& ach,const Handle(StepData_ESDescr)& descr,StepData_FieldList& list) const;
  //! Reads parameter <nump> of record <num> into a Transient Value <br>
//!           according to the type of the parameter : <br>
//!           Named for Integer,Boolean,Logical,Enum,Real : SelectNamed <br>
//!           Immediate Integer,Boolean,Logical,Enum,Real : SelectInt/Real <br>
//!           Text  : HAsciiString <br>
//!           Ident : the referenced Entity <br>
//!           Sub-List not processed, see ReadSub <br>
//!           This value is controlled by a Parameter Descriptor (PDescr), <br>
//!           which controls its allowed type and value <br>
//!           <ach> is filled if the read parameter does not match its <br>
//!           description (the select is nevertheless created if possible) <br>
//! <br>
//!  Warning : val is in out, hence it is possible to predefine a specific <br>
//!           SelectMember then to fill it. If <val> is Null or if the <br>
//!           result is not a SelectMember, val itself is returned a new ref <br>
//!           For a Select with a Name, <val> must then be a SelectNamed <br>
  Standard_EXPORT     Standard_Boolean ReadAny(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach,const Handle(StepData_PDescr)& descr,Handle(Standard_Transient)& val) const;
  //! reads parameter <nump> of record <num> as a sub-list of <br>
//!           two Reals X,Y. Returns True if OK. Else, returns false and <br>
//!           feeds Check with appropriate Fails (parameter not a sub-list, <br>
//!           not two Reals in the sub-list) composed with "mess" which <br>
//!           gives the name of the parameter <br>
  Standard_EXPORT     Standard_Boolean ReadXY(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach,Standard_Real& X,Standard_Real& Y) const;
  //! reads parameter <nump> of record <num> as a sub-list of <br>
//!           three Reals X,Y,Z. Return value and Check managed as by <br>
//!           ReadXY (demands a sub-list of three Reals) <br>
  Standard_EXPORT     Standard_Boolean ReadXYZ(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach,Standard_Real& X,Standard_Real& Y,Standard_Real& Z) const;
  //! reads parameter <nump> of record <num> as a single Real value. <br>
//!           Return value and Check managed as by ReadXY (demands a Real) <br>
  Standard_EXPORT     Standard_Boolean ReadReal(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach,Standard_Real& val) const;
  //! Reads parameter <nump> of record <num> as a single Entity. <br>
//!           Return value and Check managed as by ReadReal (demands a <br>
//!           reference to an Entity). In Addition, demands read Entity <br>
//!           to be Kind of a required Type <atype>. <br>
//!           Remark that returned status is False and <ent> is Null if <br>
//!           parameter is not an Entity, <ent> remains Not Null is parameter <br>
//!           is an Entity but is not Kind of required type <br>
  Standard_EXPORT     Standard_Boolean ReadEntity(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach,const Handle(Standard_Type)& atype,Handle(Standard_Transient)& ent) const;
  //! Same as above, but a SelectType checks Type Matching, and <br>
//!          records the read Entity (see method Value from SelectType) <br>
  Standard_EXPORT     Standard_Boolean ReadEntity(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach,StepData_SelectType& sel) const;
  //! reads parameter <nump> of record <num> as a single Integer. <br>
//!           Return value & Check managed as by ReadXY (demands an Integer) <br>
  Standard_EXPORT     Standard_Boolean ReadInteger(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach,Standard_Integer& val) const;
  //! reads parameter <nump> of record <num> as a Boolean <br>
//!           Return value and Check managed as by ReadReal (demands a <br>
//!           Boolean enum, i.e. text ".T." for True or ".F." for False) <br>
  Standard_EXPORT     Standard_Boolean ReadBoolean(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach,Standard_Boolean& flag) const;
  //! reads parameter <nump> of record <num> as a Logical <br>
//!           Return value and Check managed as by ReadBoolean (demands a <br>
//!           Logical enum, i.e. text ".T.", ".F.", or ".U.") <br>
  Standard_EXPORT     Standard_Boolean ReadLogical(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach,StepData_Logical& flag) const;
  //! reads parameter <nump> of record <num> as a String (text <br>
//!           between quotes, quotes are removed by the Read operation) <br>
//!           Return value and Check managed as by ReadXY (demands a String) <br>
  Standard_EXPORT     Standard_Boolean ReadString(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach,Handle(TCollection_HAsciiString)& val) const;
  
  Standard_EXPORT     Standard_Boolean ReadEnumParam(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach,Standard_CString& text) const;
  //! Fills a check with a fail message if enumeration value does <br>
//!           match parameter definition <br>
//!           Just a help to centralize message definitions <br>
  Standard_EXPORT     void FailEnumValue(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach) const;
  //! Reads parameter <nump> of record <num> as an Enumeration (text <br>
//!           between dots) and converts it to an integer value, by an <br>
//!           EnumTool. Returns True if OK, false if : this parameter is not <br>
//!           enumeration, or is not recognized by the EnumTool (with fail) <br>
  Standard_EXPORT     Standard_Boolean ReadEnum(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach,const StepData_EnumTool& enumtool,Standard_Integer& val) const;
  //! Resolves a parameter which can be enclosed in a type def., as <br>
//!           TYPE(val). The parameter must then be read normally according <br>
//!           its type.  Parameter to be resolved is <nump> of record <num> <br>
//!           <mustbetyped> True  demands a typed parameter <br>
//!           <mustbetyped> False accepts a non-typed parameter as option <br>
//!           mess and ach as usual <br>
//!           <numr>,<numrp> are the resolved record and parameter numbers <br>
//!             = num,nump if no type,  else numrp=1 <br>
//!           <typ> returns the recorded type, or empty string <br>
//!           Remark : a non-typed list is considered as "non-typed" <br>
  Standard_EXPORT     Standard_Boolean ReadTypedParam(const Standard_Integer num,const Standard_Integer nump,const Standard_Boolean mustbetyped,const Standard_CString mess,Handle(Interface_Check)& ach,Standard_Integer& numr,Standard_Integer& numrp,TCollection_AsciiString& typ) const;
  //! Checks if parameter <nump> of record <num> is given as Derived <br>
//!           If this Check is successful (i.e. Param = "*"), returns True <br>
//!           Else, fills <ach> with a Message which contains <mess> and <br>
//!           returns False. According to <errstat>, this message is Warning <br>
//!           if errstat is False (Default), Fail if errstat is True <br>
  Standard_EXPORT     Standard_Boolean CheckDerived(const Standard_Integer num,const Standard_Integer nump,const Standard_CString mess,Handle(Interface_Check)& ach,const Standard_Boolean errstat = Standard_False) const;
  //! Returns total count of Entities (including Header) <br>
  Standard_EXPORT   virtual  Standard_Integer NbEntities() const;
  //! determines the first suitable record following a given one <br>
//!           that is, skips SCOPE,ENDSCOPE and SUBLIST records <br>
//!           Note : skips Header records, which are accessed separately <br>
  Standard_EXPORT     Standard_Integer FindNextRecord(const Standard_Integer num) const;
  //! determines reference numbers in EntityNumber fields <br>
//!           called by Prepare from StepReaderTool to prepare later using <br>
//!           by a StepModel. This method is attached to StepReaderData <br>
//!           because it needs a massive amount of data accesses to work <br>
//! <br>
//!           If <withmap> is given False, the basic exploration algorithm <br>
//!           is activated, otherwise a map is used as far as it is possible <br>
//!           this option can be used only to test this algorithm <br>
  Standard_EXPORT     void SetEntityNumbers(const Standard_Boolean withmap = Standard_True) ;
  //! determine first suitable record of Header <br>
//!           works as FindNextRecord, but treats only Header records <br>
  Standard_EXPORT     Standard_Integer FindNextHeaderRecord(const Standard_Integer num) const;
  //! Works as SetEntityNumbers but for Header : more simple because <br>
//!           there are no Reference, only Sub-Lists <br>
  Standard_EXPORT     void PrepareHeader() ;
  //! Returns the Global Check. It can record Fail messages about <br>
//!           Undefined References (detected by SetEntityNumbers) <br>
  Standard_EXPORT    const Handle_Interface_Check GlobalCheck() const;




  DEFINE_STANDARD_RTTI(StepData_StepReaderData)

protected:




private: 

  //! Searches for a Parameter of the record <num>, which refers to <br>
//!           the Ident <id> (form #nnn). [Used by SetEntityNumbers] <br>
//!           If found, returns its EntityNumber, else returns Zero. <br>
  Standard_EXPORT     Standard_Integer FindEntityNumber(const Standard_Integer num,const Standard_Integer id) const;

TColStd_Array1OfInteger theidents;
TColStd_Array1OfInteger thetypes;
Interface_IndexedMapOfAsciiString thenametypes;
TColStd_DataMapOfIntegerInteger themults;
Standard_Integer thenbents;
Standard_Integer thelastn;
Standard_Integer thenbhead;
Standard_Integer thenbscop;
Handle_Interface_Check thecheck;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif