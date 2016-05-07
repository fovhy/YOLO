class Physic{
public:
    Physic();
    ~Physic();

    static float calculateSpeed(float currentSpeed, float force, float mass);


private:
   const float G = 9.8f;
   float friction;

};
