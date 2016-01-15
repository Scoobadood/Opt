/**
  \file App.h

  The G3D 10.00 default starter app is configured for OpenGL 3.3 and
  relatively recent GPUs.
 */
#ifndef App_h
#define App_h
#include <G3D/G3DAll.h>

#include "OpenMesh.h"

/** Application framework. */
class App : public GApp {
protected:
    float m_scaleFactor;

    CFrame m_modelFrame;

    Point3 m_currentConstraintPosition;
    int m_selectedIndex; 

    SimpleMesh m_mesh;

    String m_meshFilename;

    Array<Point3> m_constraints;
    Array<int> m_constraintIndices;

    String m_markerFilename;

    /** Called from onInit */
    void makeGUI();

    void setNewIndex(int index);

    void saveMarkerFile();

    void loadMarkerFile();

    Vector3 App::toVec3(const Vec3f& v);

public:
    
    App(const GApp::Settings& settings = GApp::Settings());

    virtual void onInit() override;
    virtual void onAI() override;
    virtual void onNetwork() override;
    virtual void onSimulation(RealTime rdt, SimTime sdt, SimTime idt) override;
    virtual void onPose(Array<shared_ptr<Surface> >& posed3D, Array<shared_ptr<Surface2D> >& posed2D) override;

    // You can override onGraphics if you want more control over the rendering loop.
    // virtual void onGraphics(RenderDevice* rd, Array<shared_ptr<Surface> >& surface, Array<shared_ptr<Surface2D> >& surface2D) override;

    virtual void onGraphics3D(RenderDevice* rd, Array<shared_ptr<Surface> >& surface3D) override;
    virtual void onGraphics2D(RenderDevice* rd, Array<shared_ptr<Surface2D> >& surface2D) override;

    virtual bool onEvent(const GEvent& e) override;
    virtual void onUserInput(UserInput* ui) override;
    virtual void onCleanup() override;
    
    /** Sets m_endProgram to true. */
    virtual void endProgram();
};

#endif