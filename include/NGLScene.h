#ifndef NGLSCENE_H__
#define NGLSCENE_H__
#include <ngl/Camera.h>
#include <ngl/Colour.h>
#include <ngl/Light.h>
#include <ngl/Transformation.h>
#include <ngl/Text.h>
#include <ngl/Obj.h>
#include <btBulletDynamicsCommon.h>
#include <QOpenGLWindow>
#include <QElapsedTimer>
#include <memory>

//----------------------------------------------------------------------------------------------------------------------
/// @file NGLScene.h
/// @brief this class inherits from the Qt OpenGLWindow and allows us to use NGL to draw OpenGL
/// @author Jonathan Macey
/// @version 1.0
/// @date 10/9/13
/// Revision History :
/// This is an initial version used for the new NGL6 / Qt 5 demos
/// @class NGLScene
/// @brief our main glwindow widget for NGL applications all drawing elements are
/// put in this file
//----------------------------------------------------------------------------------------------------------------------
class PhysicsWorld;

class NGLScene : public QOpenGLWindow
{
  public:
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief ctor for our NGL drawing class
    /// @param [in] parent the parent window to the class
    //----------------------------------------------------------------------------------------------------------------------
    NGLScene();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief dtor must close down ngl and release OpenGL resources
    //----------------------------------------------------------------------------------------------------------------------
    ~NGLScene();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the initialize class is called once when the window is created and we have a valid GL context
    /// use this to setup any default GL stuff
    //----------------------------------------------------------------------------------------------------------------------
    void initializeGL();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this is called everytime we want to draw the scene
    //----------------------------------------------------------------------------------------------------------------------
    void paintGL();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this is called everytime we resize
    //----------------------------------------------------------------------------------------------------------------------
    // Qt 5.5.1 must have this implemented and uses it
    void resizeGL(QResizeEvent *_event);
    // Qt 5.x uses this instead! http://doc.qt.io/qt-5/qopenglwindow.html#resizeGL
    void resizeGL(int _w, int _h);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief  toggle the animation and simulation
    //----------------------------------------------------------------------------------------------------------------------
     inline void toggleAnimation(){m_animate ^=true;}
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief step the animation when in anim off mode
     //----------------------------------------------------------------------------------------------------------------------
     void stepAnimation();
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief add a cube to the simulation
     //----------------------------------------------------------------------------------------------------------------------
     void addCube();
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief add a sphere to the simulation
     //----------------------------------------------------------------------------------------------------------------------
     void addSphere();
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief add a teapot to the simulation
     //----------------------------------------------------------------------------------------------------------------------

     //----------------------------------------------------------------------------------------------------------------------
     /// @brief reset the simulation and remove all bodies
     //----------------------------------------------------------------------------------------------------------------------
     void resetSim();
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief tobble the random placement of objects when added
     //----------------------------------------------------------------------------------------------------------------------
     inline void toggleRandomPlace(){m_randomPlace^=true;}
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief toggle drawing mesh bounding boxes
     //----------------------------------------------------------------------------------------------------------------------
     inline void toggleBBox(){m_bboxDraw^=true;}
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief toggle drawing wireframe meshes
     //----------------------------------------------------------------------------------------------------------------------
     inline void toggleWireframe(){m_wireframe^=true;}
     //----------------------------------------------------------------------------------------------------------------------
     /// @brief access the physics world
     //----------------------------------------------------------------------------------------------------------------------
     inline PhysicsWorld *getPhysicsWorld(){return m_physics;}


private:
     float m_x;
     float m_y;
     float m_rot;
     ngl::Vec3 m_firePos;
     float m_radius;
     //----------------------------------------------------------------------------------------------------------------------
      /// @brief window width
      //----------------------------------------------------------------------------------------------------------------------
      int m_width;
      //----------------------------------------------------------------------------------------------------------------------
      /// @brief window height
      //----------------------------------------------------------------------------------------------------------------------
      int m_height;


    //----------------------------------------------------------------------------------------------------------------------
    /// @brief used to store the x rotation mouse value
    //----------------------------------------------------------------------------------------------------------------------
    int m_spinXFace;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief used to store the y rotation mouse value
    //----------------------------------------------------------------------------------------------------------------------
    int m_spinYFace;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief flag to indicate if the mouse button is pressed when dragging
    //----------------------------------------------------------------------------------------------------------------------
    bool m_rotate;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief flag to indicate if the Right mouse button is pressed when dragging
    //----------------------------------------------------------------------------------------------------------------------
    bool m_translate;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the previous x mouse value
    //----------------------------------------------------------------------------------------------------------------------
    int m_origX;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the previous y mouse value
    //----------------------------------------------------------------------------------------------------------------------
    int m_origY;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the previous x mouse value for Position changes
    //----------------------------------------------------------------------------------------------------------------------
    int m_origXPos;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the previous y mouse value for Position changes
    //----------------------------------------------------------------------------------------------------------------------
    int m_origYPos;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Our Camera
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Camera m_cam;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief body transform matrix
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Mat4 m_bodyTransform;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief world / mouse transform
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Mat4 m_globalTransformMatrix;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the model position for mouse movement
    //----------------------------------------------------------------------------------------------------------------------
    ngl::Vec3 m_modelPos;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief the ODE physics wrapper
    //----------------------------------------------------------------------------------------------------------------------
    PhysicsWorld *m_physics;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief flag to animate / simulate
    //----------------------------------------------------------------------------------------------------------------------
    bool m_animate;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief flag for random placement of objects
    //----------------------------------------------------------------------------------------------------------------------
    bool m_randomPlace;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief flag for drawing bounding boxes
    //----------------------------------------------------------------------------------------------------------------------
    bool m_bboxDraw;
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief flag for wireframe drawing
    //----------------------------------------------------------------------------------------------------------------------
    bool m_wireframe;
    //----------------------------------------------------------------------------------------------------------------------
    ///@brief text for rendering
    //----------------------------------------------------------------------------------------------------------------------
    std::unique_ptr<ngl::Text>m_text;
    int m_numBlocks;

    //----------------------------------------------------------------------------------------------------------------------
    /// @brief method to load transform matrices to the shader
    //----------------------------------------------------------------------------------------------------------------------
    void loadMatricesToShader();
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief Qt Event called when a key is pressed
    /// @param [in] _event the Qt event to query for size etc
    //----------------------------------------------------------------------------------------------------------------------
    void keyPressEvent(QKeyEvent *_event);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called every time a mouse is moved
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void mouseMoveEvent (QMouseEvent * _event );
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse button is pressed
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void mousePressEvent ( QMouseEvent *_event);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse button is released
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void mouseReleaseEvent ( QMouseEvent *_event );

    //----------------------------------------------------------------------------------------------------------------------
    /// @brief this method is called everytime the mouse wheel is moved
    /// inherited from QObject and overridden here.
    /// @param _event the Qt Event structure
    //----------------------------------------------------------------------------------------------------------------------
    void wheelEvent( QWheelEvent *_event);
    //----------------------------------------------------------------------------------------------------------------------
    /// @brief
    //----------------------------------------------------------------------------------------------------------------------
    void timerEvent(QTimerEvent *);


};



#endif
