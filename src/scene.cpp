#include "scene.hpp"

SceneObject::SceneObject(int type, double x, double y, double z){
    this->pos = vec3(x, y, z);
};

SceneObject::SceneObject(int type, double x, double y, double z, double arg1, double arg2, double arg3){
    this->pos = vec3(x, y, z);
    this->arg = vec3(arg1, arg2, arg3);
};

Scene::Scene() {}

void Scene::add_object(SceneObject obj) {
    objs.emplace_back(obj);
}