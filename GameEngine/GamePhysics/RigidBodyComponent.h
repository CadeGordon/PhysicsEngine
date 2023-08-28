#pragma once
#include "GameCore/TransformComponent.h"
#include "Vector3.h"
#include "ColliderComponent.h"

namespace GamePhysics
{
    class RigidBodyComponent :
        public GameCore::TransformComponent
    {
    public:
        RigidBodyComponent(float mass, float elasticty);

        //Handles the pshyics updates
        void onFixedUpdate(float fixedDelaTime) override;

        //Applys a force to the entites
        void applyForce(GameMath::Vector3 force, float Time = 1.0f);

        /// <summary>
        /// gets the mass of the entity or entities in the scene
        /// </summary>
        /// <returns> gets the mass of the entity</returns>
        float getMass() { return m_mass; }
        /// <summary>
        /// Sets the mass the of entity or entities
        /// </summary>
        /// <param name="mass"></param>
        void setMass(float mass) { m_mass = mass; }
        /// <summary>
        /// Gets the gravity of the entity or entites
        /// </summary>
        /// <returns> gets the gravity of entity</returns>
        GameMath::Vector3 getGravity() { return m_gravity; }
        /// <summary>
        /// sets the gravity of entity or entities
        /// </summary>
        /// <param name="gravity"></param>
        void setGravity(GameMath::Vector3 gravity) { m_gravity = gravity; }
        /// <summary>
        /// gets the accerleration of entity or entities
        /// </summary>
        /// <returns>m_acceleration</returns>
        GameMath::Vector3 getAcceleration() { return m_acceleration; }
        /// <summary>
        /// Sets the accerleration of entites or entity
        /// </summary>
        /// <param name="acceleration"></param>
        void setAccerlation(GameMath::Vector3 acceleration) { m_acceleration = acceleration; }
        /// <summary>
        /// Gets the velocity of the entity or entities
        /// </summary>
        /// <returns>m_velocity</returns>
        GameMath::Vector3 getVelocity() { return m_velocity; }
        /// <summary>
        /// Sets the velocity
        /// </summary>
        /// <param name="velocity"></param>
        void setVelocity(GameMath::Vector3 velocity) { m_gravity = velocity; }
        /// <summary>
        /// Gets the elasticity
        /// </summary>
        /// <returns>m_elasticity</returns>
        float getElasticity() { return m_elasticity; }
        /// <summary>
        /// sets the elasticity
        /// </summary>
        /// <param name="elasticity"></param>
        void setElasticity(float elasticity) { m_elasticity = elasticity; }
        /// <summary>
        /// gets the collision normal
        /// </summary>
        /// <param name="other">Rigidbody component</param>
        /// <returns>global and others global position</returns>
        GameMath::Vector3 getCollisionNomral(RigidBodyComponent* other);
        /// <summary>
        /// Gets the impulse
        /// </summary>
        /// <param name="other"> the left hand side</param>
        /// <param name="collisionNormal"> and right side</param>
        /// <returns>impulse</returns>
        float getImpulse(RigidBodyComponent* other, GameMath::Vector3 collisionNormal);

        /// <summary>
        /// 
        /// </summary>
        /// <param name="other">RigidBodyComponent</param>
        void resloveCollision(RigidBodyComponent other);

        
        


    private:
        float m_mass = 1.0f;
        float m_elasticity = 1.0f;

        GameMath::Vector3 m_velocity = GameMath::Vector3(0.0f, 0.0f, 0.0f);
        GameMath::Vector3 m_acceleration = GameMath::Vector3(0.0f, 0.0f, 0.0f);
        GameMath::Vector3 m_gravity = GameMath::Vector3(0.0f, -9.81f, 0.0f);
        bool m_usingGravity = false;
        bool m_isKinematic = false;


    };
}


