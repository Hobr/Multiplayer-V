#pragma once

#include <Common.h>
#include <World/Entity.h>

#include <Octree.h>

class WorldNode
{
public:
	std::vector<Entity*> m_entities;
};

class World
{
public:
	Octree<WorldNode> m_entities;
	std::unordered_map<uint32_t, Entity*> m_allEntities;

public:
	World();
	~World();

	void Initialize();

	void Delete();

	void AddToOctree(Entity* ent);
	void RemoveFromOctree(Entity* ent);
	void RebuildOctree();

	void QueryRange(const glm::vec3 &pos, float range, std::vector<Entity*> &out, Entity* except = nullptr);

	void AddEntity(Entity* ent);
	void RemoveEntity(Entity* ent);
	Entity* GetEntityFromHandle(const NetHandle &handle);
	template<typename T>
	T* GetEntityFromHandle(const NetHandle &handle)
	{
		return static_cast<T*>(GetEntityFromHandle(handle));
	}

	void EntityMoved(Entity* ent, const glm::vec3 &oldPos);

	void Update();
};
