// This file is generated by WOK (CPPExt).
// Please do not edit this file; modify original file instead.
// The copyright and license terms as defined for the original file apply to 
// this header file considered to be the "object code" form of the original source.

#ifndef _Graphic2d_TransientManager_HeaderFile
#define _Graphic2d_TransientManager_HeaderFile

#ifndef _Standard_HeaderFile
#include <Standard.hxx>
#endif
#ifndef _Standard_DefineHandle_HeaderFile
#include <Standard_DefineHandle.hxx>
#endif
#ifndef _Handle_Graphic2d_TransientManager_HeaderFile
#include <Handle_Graphic2d_TransientManager.hxx>
#endif

#ifndef _Graphic2d_ViewPtr_HeaderFile
#include <Graphic2d_ViewPtr.hxx>
#endif
#ifndef _gp_GTrsf2d_HeaderFile
#include <gp_GTrsf2d.hxx>
#endif
#ifndef _Graphic2d_TypeOfComposition_HeaderFile
#include <Graphic2d_TypeOfComposition.hxx>
#endif
#ifndef _Standard_Boolean_HeaderFile
#include <Standard_Boolean.hxx>
#endif
#ifndef _Aspect_TypeOfPrimitive_HeaderFile
#include <Aspect_TypeOfPrimitive.hxx>
#endif
#ifndef _Graphic2d_Drawer_HeaderFile
#include <Graphic2d_Drawer.hxx>
#endif
#ifndef _Handle_Graphic2d_View_HeaderFile
#include <Handle_Graphic2d_View.hxx>
#endif
#ifndef _Handle_Aspect_WindowDriver_HeaderFile
#include <Handle_Aspect_WindowDriver.hxx>
#endif
#ifndef _Handle_Graphic2d_ViewMapping_HeaderFile
#include <Handle_Graphic2d_ViewMapping.hxx>
#endif
#ifndef _Standard_Real_HeaderFile
#include <Standard_Real.hxx>
#endif
#ifndef _Handle_Graphic2d_Primitive_HeaderFile
#include <Handle_Graphic2d_Primitive.hxx>
#endif
#ifndef _Handle_Graphic2d_GraphicObject_HeaderFile
#include <Handle_Graphic2d_GraphicObject.hxx>
#endif
#ifndef _Standard_Integer_HeaderFile
#include <Standard_Integer.hxx>
#endif
#ifndef _Quantity_Length_HeaderFile
#include <Quantity_Length.hxx>
#endif
#ifndef _Quantity_PlaneAngle_HeaderFile
#include <Quantity_PlaneAngle.hxx>
#endif
#ifndef _Aspect_TypeOfText_HeaderFile
#include <Aspect_TypeOfText.hxx>
#endif
#ifndef _Graphic2d_TypeOfAlignment_HeaderFile
#include <Graphic2d_TypeOfAlignment.hxx>
#endif
#ifndef _Quantity_Ratio_HeaderFile
#include <Quantity_Ratio.hxx>
#endif
#ifndef _Quantity_Factor_HeaderFile
#include <Quantity_Factor.hxx>
#endif
class Graphic2d_TransientDefinitionError;
class Graphic2d_View;
class Aspect_WindowDriver;
class Graphic2d_ViewMapping;
class Graphic2d_Primitive;
class Graphic2d_GraphicObject;
class TCollection_ExtendedString;
class gp_GTrsf2d;


//! This class allows to manage transient graphics <br>
//!	    above one View. <br>
//!	    A simple way to drawn something very quicly above <br>
//!	    a complex scene (Hilighting,Sketching,...) <br>
//!	    All transient graphics will be erased at the <br>
//!	    next View::Update(),Redraw(). <br>
class Graphic2d_TransientManager : public Graphic2d_Drawer {

public:

  
  Standard_EXPORT   Graphic2d_TransientManager(const Handle(Graphic2d_View)& aView);
  //! Creates a TransientManager associated to the view <aView> <br>
  Standard_EXPORT   Graphic2d_TransientManager(const Graphic2d_ViewPtr& aView);
  //! Suppress the TransientManager <me>. <br>
  Standard_EXPORT     void Destroy() ;
~Graphic2d_TransientManager()
{
  Destroy();
}
  //! Begins any graphics in the view <aView> and Driver <aDriver> <br>
//!	    with the current view attributes in a transient area. <br>
//!          Restore the front buffer from the back before <br>
//!	    if <ClearBefore> is TRUE. <br>
//! <br>
//!  Warning: Returns TRUE if transient backing-store is enabled in <br>
//!	   the associated view. <br>
//!          Returns FALSE ,if nothing works because something <br>
//!	   is wrong for the transient principle : <br>
//!	   Immediat mode is not implemented depending of the <br>
//!	   graphic library used. <br>
//!  	   MBX,PIXMAP double buffering don't works depending of <br>
//!  	   the graphic board and the visual of the window supporting <br>
//!  	   the view. <br>
  Standard_EXPORT     Standard_Boolean BeginDraw(const Handle(Aspect_WindowDriver)& aDriver,const Standard_Boolean ClearBefore = Standard_True) ;
  //! Begins any graphics in the view <aView> and Driver <aDriver> <br>
//!	    with the view attributes in a transient area defined <br>
//!	    by : <br>
//!          <aViewMapping> defines the "map from". <br>
//!          <aXPosition>, <aYPosition>, <aScale> define the "map to". <br>
//!          Restore the front buffer from the back before <br>
//!	    if <ClearBefore> is TRUE. <br>
  Standard_EXPORT     Standard_Boolean BeginDraw(const Handle(Aspect_WindowDriver)& aDriver,const Handle(Graphic2d_ViewMapping)& aViewMapping,const Standard_Real aXPosition,const Standard_Real aYPosition,const Standard_Real aScale,const Standard_Boolean ClearBefore = Standard_True) ;
  //! Flush all graphics to the front buffer. <br>
//!	Synchronize graphics to the screen if <Synchronize> is <br>
//!	TRUE (make becarefull to the performances!). <br>
  Standard_EXPORT     void EndDraw(const Standard_Boolean Synchronize = Standard_True) ;
  //! Restore the full transient view, <br>
//!          returns TRUE if the transient area has been restored <br>
//!	    correctly or FALSE if the view has been redrawn. <br>
  Standard_EXPORT     Standard_Boolean Restore(const Handle(Aspect_WindowDriver)& aDriver) ;
  //! Restore the last updated transient area, <br>
//!          returns TRUE if the transient area has been restored <br>
//!	    correctly or FALSE if the view has been redrawn. <br>
  Standard_EXPORT     Standard_Boolean RestoreArea(const Handle(Aspect_WindowDriver)& aDriver) ;
  //! Drawn the primitive <aPrimitive>, <br>
//!	    with the internal primitive attributes. <br>
  Standard_EXPORT     void Draw(const Handle(Graphic2d_Primitive)& aPrimitive) ;
  //! Drawn the graphic object <aGraphicObject>. <br>
//!	    with the internal graphic object primitives attributes. <br>
  Standard_EXPORT     void Draw(const Handle(Graphic2d_GraphicObject)& aGraphicObject) ;
  //! Drawn the element <anIndex> from the primitive <aPrimitive>, <br>
//!	    with the internal primitive attributes. <br>
  Standard_EXPORT     void DrawElement(const Handle(Graphic2d_Primitive)& aPrimitive,const Standard_Integer anIndex) ;
  //! Draws all picked elements. <br>
  Standard_EXPORT     void DrawPickedElements(const Handle(Graphic2d_Primitive)& aPrimitive) ;
  //! Drawn the vertex <anIndex> from the primitive <aPrimitive>, <br>
//!	    with the internal primitive attributes. <br>
  Standard_EXPORT     void DrawVertex(const Handle(Graphic2d_Primitive)& aPrimitive,const Standard_Integer anIndex) ;
  //! Sets the current type of primitive to be opened. <br>
//!          After this call, <me> is ready to receive <br>
//!          a definition of an incremental primitive <br>
//!          such as a polyline or polygon with DrawPoint(), <br>
//!          or the definition of a set of primitives such as <br>
//!          a segment with DrawSegment() or DrawMarker(). <br>
//!  Warning: The max number of element of the primitive can be defined <br>
//!          with <aSize> for optimization. <br>
//!  Example: This sequence drawn a polyline square of size 1. <br>
//!	    myTransientManager->BeginDraw(myDriver) <br>
//!	    myTransientManager->BeginPrimitive(Aspect_TOP_POLYLINE,5) <br>
//!	    myTransientManager->DrawPoint(-0.5,-0.5) <br>
//!	    myTransientManager->DrawPoint(-0.5, 0.5) <br>
//!	    myTransientManager->DrawPoint( 0.5, 0.5) <br>
//!	    myTransientManager->DrawPoint( 0.5,-0.5) <br>
//!	    myTransientManager->DrawPoint(-0.5,-0.5) <br>
//!	    myTransientManager->ClosePrimitive() <br>
//!	    myTransientManager->EndDraw() <br>
  Standard_EXPORT     void BeginPrimitive(const Aspect_TypeOfPrimitive aType,const Standard_Integer aSize = 0) ;
  //! After this call, <me> stops the reception of <br>
//!          a definition of a Begin... primitive. <br>
  Standard_EXPORT     void ClosePrimitive() ;
  //! Draw a segment. <br>
  Standard_EXPORT     void DrawSegment(const Quantity_Length X1,const Quantity_Length Y1,const Quantity_Length X2,const Quantity_Length Y2) ;
  //! Draw an infinite line defined by a reference point <X,Y> <br>
//!          and a slope <Dx,Dy> <br>
  Standard_EXPORT     void DrawInfiniteLine(const Quantity_Length X,const Quantity_Length Y,const Quantity_Length Dx,const Quantity_Length Dy) ;
  //! Draw a circle arc from the start angle <anAngle1> <br>
//!	   to the ending angle <anAngle2>. <br>
//!	    NOTE that if <anAngle2> is equal to <anAngle1> <br>
//!	    a full circle is drawn. <br>
  Standard_EXPORT     void DrawArc(const Quantity_Length Xc,const Quantity_Length Yc,const Quantity_Length aRadius,const Quantity_PlaneAngle anAngle1 = 0.0,const Quantity_PlaneAngle anAngle2 = 0.0) ;
  //! Draw a filled circle arc from the start angle <anAngle1> <br>
//!	   to the ending angle <anAngle2>. <br>
//!	    NOTE that if <anAngle2> is equal to <anAngle1> <br>
//!	    a full circle is drawn. <br>
  Standard_EXPORT     void DrawPolyArc(const Quantity_Length Xc,const Quantity_Length Yc,const Quantity_Length aRadius,const Quantity_PlaneAngle anAngle1 = 0.0,const Quantity_PlaneAngle anAngle2 = 0.0) ;
  //! Draw a marker point. <br>
  Standard_EXPORT     void DrawPoint(const Quantity_Length X,const Quantity_Length Y) ;
  //! Draw an indexed marker. <br>
  Standard_EXPORT     void DrawMarker(const Standard_Integer anIndex,const Quantity_Length X,const Quantity_Length Y,const Quantity_Length aWidth,const Quantity_Length anHeight,const Quantity_PlaneAngle anAngle = 0.0) ;
  //! Draw a text at the position <X,Y> added to <br>
//!         the untransformed drawer offset <aDeltaX,aDeltaY> , <br>
//!         with an orientation <anAngle> and a type <aType>. <br>
  Standard_EXPORT     void DrawText(const TCollection_ExtendedString& aText,const Quantity_Length X,const Quantity_Length Y,const Quantity_PlaneAngle anAngle = 0.0,const Standard_Real aDeltaX = 0.0,const Standard_Real aDeltaY = 0.0,const Aspect_TypeOfText aType = Aspect_TOT_SOLID,const Graphic2d_TypeOfAlignment anAlignment = Graphic2d_TOA_LEFT) ;
  //! Draw an hiding text at the position <X,Y> added to <br>
//!         the untransformed offset <aDeltaX,aDeltaY> , <br>
//!         with an orientation <anAngle> and a type <aType>. <br>
//!         <aMargin> defined the relative margin factor between <br>
//!         the text string and the frame height. <br>
  Standard_EXPORT     void DrawPolyText(const TCollection_ExtendedString& aText,const Quantity_Length X,const Quantity_Length Y,const Quantity_PlaneAngle anAngle = 0.0,const Quantity_Ratio aMargin = 0.1,const Standard_Real aDeltaX = 0.0,const Standard_Real aDeltaY = 0.0,const Aspect_TypeOfText aType = Aspect_TOT_SOLID,const Graphic2d_TypeOfAlignment anAlignment = Graphic2d_TOA_LEFT) ;
  //! Draw a framed text at the position <X,Y> added to <br>
//!         the untransformed offset <aDeltaX,aDeltaY> , <br>
//!         with an orientation <anAngle> and a type <aType>. <br>
//!         <aMargin> defined the relative margin factor between <br>
//!         the text string and the frame height. <br>//! Draw a curve. <br>
//!        raises TransientDefinitionError from Graphic2d is static; <br>
  Standard_EXPORT     void DrawFramedText(const TCollection_ExtendedString& aText,const Quantity_Length X,const Quantity_Length Y,const Quantity_PlaneAngle anAngle = 0.0,const Quantity_Ratio aMargin = 0.1,const Standard_Real aDeltaX = 0.0,const Standard_Real aDeltaY = 0.0,const Aspect_TypeOfText aType = Aspect_TOT_SOLID,const Graphic2d_TypeOfAlignment anAlignment = Graphic2d_TOA_LEFT) ;
  //! Methods to define the Current Text Attributes <br>
//!	    NOTE that ,if isZoomable is TRUE the text size follow <br>
//!	    the scale factor of the view and the current transformation <br>
//!	    scale factor. <br>
  Standard_EXPORT     void SetTextAttrib(const Standard_Integer ColorIndex,const Standard_Integer FontIndex,const Quantity_PlaneAngle aSlant = 0.0,const Quantity_Factor aHScale = 1.0,const Quantity_Factor aWScale = 1.0,const Standard_Boolean isUnderlined = Standard_False,const Standard_Boolean isZoomable = Standard_True) ;
  //! Methods to define the Current Hiding Text Attributes <br>
//!	    NOTE that ,if isZoomable is TRUE the text size follow <br>
//!	    the scale factor of the view and the current transformation <br>
//!	    scale factor. <br>
  Standard_EXPORT     void SetHidingTextAttrib(const Standard_Integer ColorIndex,const Standard_Integer HidingColorIndex,const Standard_Integer FrameColorIndex,const Standard_Integer FrameWidthIndex,const Standard_Integer FontIndex,const Quantity_PlaneAngle aSlant = 0.0,const Quantity_Factor aHScale = 1.0,const Quantity_Factor aWScale = 1.0,const Standard_Boolean isUnderlined = Standard_False,const Standard_Boolean isZoomable = Standard_True) ;
  //! Methods to define the Current Framed Text Attributes <br>
//!	    NOTE that ,if isZoomable is TRUE the text size follow <br>
//!	    the scale factor of the view and the current transformation <br>
//!	    scale factor. <br>
  Standard_EXPORT     void SetFramedTextAttrib(const Standard_Integer ColorIndex,const Standard_Integer FrameColorIndex,const Standard_Integer FrameWidthIndex,const Standard_Integer FontIndex,const Quantity_PlaneAngle aSlant = 0.0,const Quantity_Factor aHScale = 1.0,const Quantity_Factor aWScale = 1.0,const Standard_Boolean isUnderlined = Standard_False,const Standard_Boolean isZoomable = Standard_True) ;
  //! Sets the current transformation <aTrsf> applied to <br>
//!          the primitives. <br>
  Standard_EXPORT     void SetTransform(const gp_GTrsf2d& aTrsf,const Graphic2d_TypeOfComposition aType = Graphic2d_TOC_REPLACE) ;
  //! Enable/Disable the mapping conversion between <br>
//!      the view and the driver system coordinates. <br>
  Standard_EXPORT     void SetMapping(const Standard_Boolean aStatus = Standard_True) ;
  //! Returns the world coordinates of the boundary box <br>
//!	    of the Transient graphics actually drawn <br>
//!	    since BeginDraw() has been call. <br>
//!  Warning: If nothing has been drawn then : <br>
//!	    XMin = YMin = RealFirst (). <br>
//!	    XMax = YMax = RealLast (). <br>
//!	    and returns a min-max status to FALSE; <br>
  Standard_EXPORT     Standard_Boolean MinMax(Quantity_Length& XMin,Quantity_Length& YMin,Quantity_Length& XMax,Quantity_Length& YMax) const;
  //! Returns the current transformation. <br>
  Standard_EXPORT     gp_GTrsf2d Transform() const;



  DEFINE_STANDARD_RTTI(Graphic2d_TransientManager)

protected:




private: 

  //! Redraw the view. <br>
  Standard_EXPORT     void Redraw(const Handle(Aspect_WindowDriver)& aDriver) ;
  //! Enable/Disable the min-max computation. <br>
//!          and reset the boundary-box if <Reset> is TRUE. <br>
  Standard_EXPORT     void EnableMinMax(const Standard_Boolean aStatus = Standard_True,const Standard_Boolean Reset = Standard_True) ;
  //! Returns TRUE if the returned pixel space min max <br>
//!          boundary box has been computed correctly arround <br>
//!          all the primitives drawn in the driver. <br>
//!  Warning: the boundary box size cannot be greater that <br>
//!          the associated window space size. <br>
//!          Returns FALSE if the min-max boundary box is NULL. <br>
  Standard_EXPORT     Standard_Boolean MinMax(Standard_Integer& aMinX,Standard_Integer& aMaxX,Standard_Integer& aMinY,Standard_Integer& aMaxY) const;

Graphic2d_ViewPtr myPView;
gp_GTrsf2d myTrsf;
gp_GTrsf2d myCompositeTrsf;
Graphic2d_TypeOfComposition myTypeOfComposition;
Standard_Boolean myDrawingIsStarted;
Standard_Boolean myTrsfIsDefined;
Standard_Boolean myMappingIsEnable;
Aspect_TypeOfPrimitive myTypeOfPrimitive;


};





// other Inline functions and methods (like "C++: function call" methods)


#endif