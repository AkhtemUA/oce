// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _PGeom_Vector_HeaderFile
#define _PGeom_Vector_HeaderFile

#include <Standard_Macro.hxx>
#include <Standard_DefineHandle.hxx>
#include <Standard.hxx>
#include <Handle_PGeom_Vector.hxx>

#include <gp_Vec.hxx>
#include <PGeom_Geometry.hxx>
class gp_Vec;


class PGeom_Vector : public PGeom_Geometry
{

public:

  
  //! Set the field vec.
  Standard_EXPORT   void Vec (const gp_Vec& aVec) ;
  
  //! Returns the value of the field vec.
  Standard_EXPORT   gp_Vec Vec()  const;

PGeom_Vector(const Storage_stCONSTclCOM& a) : PGeom_Geometry(a)
{
  
}
    const gp_Vec& _CSFDB_GetPGeom_Vectorvec() const { return vec; }



  DEFINE_STANDARD_RTTI(PGeom_Vector)

protected:

  
  //! Initializes the field(s) with default value(s).
  Standard_EXPORT PGeom_Vector();
  
  //! Initializes the field vec with <aVec>.
  Standard_EXPORT PGeom_Vector(const gp_Vec& aVec);

  gp_Vec vec;


private: 




};







#endif // _PGeom_Vector_HeaderFile
