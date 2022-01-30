class ParkingSystem {
    vector<int> slots;
    
public:
    ParkingSystem(int big, int medium, int small) {
        slots = { big, medium, small };
    }
    
    bool addCar(int carType) {
        bool carAdded =  false;
        if (slots[carType - 1] > 0) {
            slots[carType - 1]--;
            carAdded = true;
        }
        return carAdded;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */