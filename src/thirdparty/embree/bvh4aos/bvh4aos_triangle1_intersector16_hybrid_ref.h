// ======================================================================== //
// Copyright 2009-2013 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#ifndef __EMBREE_BVH4AOS_TRIANGLE1_INTERSECTOR16_HYBRID_REF_H__
#define __EMBREE_BVH4AOS_TRIANGLE1_INTERSECTOR16_HYBRID_REF_H__

#include "bvh4aos.h"
#include "../common/ray16.h"
#include "../include/intersector16.h"
#include "../geometry/triangle1.h"

namespace embree
{
  /*! BVH4AOS Traverser. Single ray traversal implementation for a Quad BVH. */
  class BVH4AOSTriangle1Intersector16HybridRef : public Intersector16
  {
  public:

    /* shortcuts for frequently used types */
    typedef Triangle1 Triangle;
    typedef typename BVH4AOS::NodeRef NodeRef;
    typedef typename BVH4AOS::Node Node;
    
  public:
    BVH4AOSTriangle1Intersector16HybridRef (const BVH4AOS* bvh) 
      : Intersector16((intersectFunc)intersect,(occludedFunc)occluded), bvh(bvh) {}

    static Intersector16* create(const Accel* bvh) { 
      return new BVH4AOSTriangle1Intersector16HybridRef((const BVH4AOS*)bvh); 
    }

    static void intersect (const BVH4AOSTriangle1Intersector16HybridRef* This, Ray16& ray, const __mmask valid);
    static __mmask occluded (const BVH4AOSTriangle1Intersector16HybridRef* This, Ray16& ray, const __mmask valid);

  private:
    const BVH4AOS* bvh;
  };
}

#endif
