//
//  c3dSubMesh.h
//  HelloCpp
//
//  Created by Yang Chao (wantnon) on 14-1-2.
//
//

#ifndef __HelloCpp__c3dSubMesh__
#define __HelloCpp__c3dSubMesh__

#include "cocos2d.h"
using namespace cocos2d;
#include<iostream>
using namespace std;
#include "c3dNode.h"

#include "c3dMatrix.h"
#include "c3dVector.h"
#include "c3dIndexVBO3d.h"
#include "c3dSubMeshData.h"
#include "c3dDefine.h"
#include "c3dCommonFunc.h"
#include "c3dDefaultPrograms.h"

#include "c3dMaterial.h"
#include "c3dCamera.h"
#include "c3dDefine.h"
#include "c3dTextureCache.h"

class Cc3dSubMesh : public Cc3dNode{
public:
	Cc3dSubMesh() {
        m_texture=NULL;
        m_subMeshData=NULL;
        m_indexVBO=NULL;
        m_material=NULL;
        m_isDoDepthTest=true;
        m_blendFunc.src=C3D_BLEND_SRC;
        m_blendFunc.dst=C3D_BLEND_DST;
        
        init_dft();
    }
	virtual ~Cc3dSubMesh(){
        if(m_texture)m_texture->release();
        if(m_subMeshData)m_subMeshData->release();
        if(m_indexVBO)m_indexVBO->release();
        if(m_material)m_material->release();
    };

    bool init();
    void setTexture(Cc3dTexture*texture);
    void setMaterial(Cc3dMaterial*material);
    void setSubMeshData(Cc3dSubMeshData*subMeshData);
    Cc3dSubMeshData*getSubMeshData(){return m_subMeshData;}
    void setIndexVBO(Cc3dIndexVBO3d*indexVBO);
    
    void submit(GLenum usage);
    void submitPosition(GLenum usage);
    void submitNormal(GLenum usage);
    void submitColor(GLenum usage);
    void submitTexCoord(GLenum usage);
    void submitIndex(GLenum usage);
	virtual void drawC3D(Renderer *renderer, const Cc3dMatrix4& modelMat);
    virtual void onDraw(const Mat4& modelMat, uint32_t flags);
    Cc3dMaterial*getMaterial(){return m_material;}
    bool getIsDoDepthTest()const;
    void setIsDoDepthTest(bool isDoDepthTest);
    void setBlendFunc(ccBlendFunc blendFunc){m_blendFunc = blendFunc;}
    ccBlendFunc getBlendFunc(){return m_blendFunc;}
    
    Cc3dVertex getVertexByIndex(int index){return m_subMeshData->getVertexByIndex(index);}
    void setVertexByIndex(int index,const Cc3dVertex&vertex){m_subMeshData->setVertexByIndex(index,vertex);}
    Cc3dIDTriangle getIDtriByIndex(int index){return m_subMeshData->getIDtriByIndex(index);}
protected:
    void init_dft();

protected:
    Cc3dTexture* m_texture;
    Cc3dMaterial* m_material;
    Cc3dSubMeshData* m_subMeshData;
    Cc3dIndexVBO3d* m_indexVBO;


    bool m_isDoDepthTest;
    ccBlendFunc m_blendFunc;
    
    
};

#endif /* defined(__HelloCpp__c3dSubMesh__) */
