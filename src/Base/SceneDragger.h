/**
   @author Shin'ichiro Nakaoka
*/

#ifndef CNOID_BASE_SCENE_DRAGGER_H
#define CNOID_BASE_SCENE_DRAGGER_H

#include "SceneWidgetEditable.h"
#include "exportdecl.h"

namespace cnoid {

class CNOID_EXPORT SceneDragger : public SgPosTransform, public SceneWidgetEditable
{
public:
    bool isContainerMode() const { return isContainerMode_; }
    void setContainerMode(bool on);

    virtual bool isDragEnabled() const = 0;
    virtual void setDragEnabled(bool on) = 0;

    virtual bool isDragging() const = 0;
    virtual Affine3 draggedPosition() const = 0;

  protected:
    SceneDragger();
    SceneDragger(const SceneDragger& org, CloneMap* cloneMap = nullptr);
    static bool detectAxisFromNodePath(const SgNodePath& path, SgNode* topNode, int& out_axis, int& out_indexOfTopNode);
        
  private:
    bool isContainerMode_;
};

typedef ref_ptr<SceneDragger> SceneDraggerPtr;

}

#endif
