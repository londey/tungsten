#ifndef SPHERE_HPP_
#define SPHERE_HPP_

#include "Primitive.hpp"

namespace Tungsten {

class Sphere : public Primitive
{
    Mat4f _rot;
    Mat4f _invRot;
    Vec3f _pos;
    float _radius;

    std::shared_ptr<TriangleMesh> _proxy;

    float solidAngle(const Vec3f &p) const;
    void buildProxy();

public:
    Sphere();
    Sphere(const Vec3f &pos, float r, const std::string &name, std::shared_ptr<Bsdf> bsdf);

    virtual void fromJson(const rapidjson::Value &v, const Scene &scene) override;
    virtual rapidjson::Value toJson(Allocator &allocator) const override;

    virtual bool intersect(Ray &ray, IntersectionTemporary &data) const override;
    virtual bool occluded(const Ray &ray) const override;
    virtual bool hitBackside(const IntersectionTemporary &data) const override;
    virtual void intersectionInfo(const IntersectionTemporary &data, IntersectionInfo &info) const override;
    virtual bool tangentSpace(const IntersectionTemporary &data, const IntersectionInfo &info, Vec3f &T, Vec3f &B) const override;

    virtual bool isSamplable() const override;
    virtual void makeSamplable() override;
    virtual float inboundPdf(const IntersectionTemporary &data, const Vec3f &p, const Vec3f &d) const override;
    virtual bool sampleInboundDirection(LightSample &sample) const override;
    virtual bool sampleOutboundDirection(LightSample &sample) const override;
    virtual bool invertParametrization(Vec2f uv, Vec3f &pos) const override;

    virtual bool isDelta() const override;
    virtual bool isInfinite() const override;

    virtual float approximateRadiance(const Vec3f &p) const override;
    virtual Box3f bounds() const override;

    virtual const TriangleMesh &asTriangleMesh() override;

    virtual void prepareForRender() override;
    virtual void cleanupAfterRender() override;

    virtual Primitive *clone() override;

    const Vec3f &pos() const
    {
        return _pos;
    }

    float radius() const
    {
        return _radius;
    }
};

}

#endif /* SPHERE_HPP_ */
