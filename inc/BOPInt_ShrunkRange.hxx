// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _BOPInt_ShrunkRange_HeaderFile
#define _BOPInt_ShrunkRange_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineAlloc_HeaderFile
#include <Standard_DefineAlloc.hxx>
#endif
#ifndef _Standard_Macro_HeaderFile
#include <Standard_Macro.hxx>
#endif

#ifndef _TopoDS_Edge_HeaderFile
#include <TopoDS_Edge.hxx>
#endif
#ifndef _TopoDS_Vertex_HeaderFile
#include <TopoDS_Vertex.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Bnd_Box_HeaderFile
#include <Bnd_Box.hxx>
#endif
#ifndef _Handle_BOPInt_Context_HeaderFile
#include <Handle_BOPInt_Context.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
class BOPInt_Context;
class TopoDS_Edge;
class TopoDS_Vertex;
class Bnd_Box;



//!  The class provides the computation of <br>
//!  a working (shrunk) range [t1, t2] for <br>
//!  the 3D-curve of the edge. <br>
class BOPInt_ShrunkRange  {
public:

  DEFINE_STANDARD_ALLOC

  
  Standard_EXPORT   BOPInt_ShrunkRange();
Standard_EXPORT virtual ~BOPInt_ShrunkRange();
  
  Standard_EXPORT     void SetData(const TopoDS_Edge& aE,const Standard_Real aT1,const Standard_Real aT2,const TopoDS_Vertex& aV1,const TopoDS_Vertex& aV2) ;
  
  Standard_EXPORT     void SetContext(const Handle(BOPInt_Context)& aCtx) ;
  
  Standard_EXPORT    const Handle_BOPInt_Context& Context() const;
  
  Standard_EXPORT     void SetShrunkRange(const Standard_Real aT1,const Standard_Real aT2) ;
  
  Standard_EXPORT     void ShrunkRange(Standard_Real& aT1,Standard_Real& aT2) const;
  
  Standard_EXPORT    const Bnd_Box& BndBox() const;
  
  Standard_EXPORT    const TopoDS_Edge& Edge() const;
  
  Standard_EXPORT     void Perform() ;
  
//! Returns code of computing shrunk range <br>
//! completion <br>
//! 0 - means successful completion <br>
//! 1 - nothing has been done <br>
//! 2 - initial range is out of edge's range <br>
//! 3 - first boundary of initial range is more than <br>
//!     last boundary <br>
//! 4 - projection of first vertex failed <br>
//! 5 - projection of second vertex failed <br>
//! 6 - shrunk range can not be computed <br>
//!     shrunk range is setted to initial range <br>
//! <br>
  Standard_EXPORT     Standard_Integer ErrorStatus() const;





protected:



TopoDS_Edge myEdge;
TopoDS_Vertex myV1;
TopoDS_Vertex myV2;
Standard_Real myT1;
Standard_Real myT2;
Standard_Real myTS1;
Standard_Real myTS2;
Bnd_Box myBndBox;
Handle_BOPInt_Context myCtx;
Standard_Integer myErrorStatus;


private:





};





// other Inline functions and methods (like "C++: function call" methods)


#endif
