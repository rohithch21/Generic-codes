class ParkedVehicle:

    # parkedStatus = "Parked"

    def __init__(self,vehSeq,fourWheeler,parkedFor,valetParking):

        self.vehSeq = vehSeq
        self.fourWheeler = fourWheeler
        self.parkedFor = parkedFor
        self.valetParking = valetParking
        self.parkedStatus = "Parked"


class ParkingLot(ParkedVehicle):

    def __init__(self,parkd_vehicles):
        self.parkd_vehicles = parkd_vehicles
    

    def updateParkedStatus(self,lot_number):
        if lot_number in self.parkd_vehicles:
            lot = self.parkd_vehicles[lot_number]  # points to a class / object
            lot.parkedStatus = "Cleared"
            return (lot_num,lot.parkedStatus)
        
        return None

        
    def getParkingCharges(self,lot_number):
        if lot_number in self.parkd_vehicles:
            self.updateParkedStatus(lot_number)
            lot = self.parkd_vehicles[lot_number]
            hours = lot.parkedFor
            if lot.fourWheeler == "Yes":
                if lot.valetParking == "Yes":
                    charges = hours*50 + 10
                else:
                    charges = hours*50
            else:
                if lot.valetParking == "Yes":
                    charges = hours*30 + 10
                else:
                    charges = hours*30

            return charges

        return None




if __name__ == "__main__":

    numParkVeh = int(input("Enter number of vehicles to be added to dict : "))
    temp = {}

    for n in range(numParkVeh):
        _vehSeq = int(input("vehSeq : "))
        _fourWheeler = input("fourWheeler : ")
        _parkedFor = float(input("parkedFor : "))
        _valetParking = input("valetParking : ")
        _lot_number = int(input("Lot Number : "))
        temp.update({_lot_number : ParkedVehicle(_vehSeq, _fourWheeler, _parkedFor, _valetParking)})
    
    lot_num = int(input("Lot number : "))

    ParkingLotObj = ParkingLot(temp)
    val = ParkingLotObj.updateParkedStatus(lot_num)
    if val == None:
        print("Lot Number Invalid")
    else:
        print(val)


    charge = ParkingLotObj.getParkingCharges(lot_num)

    if charge == None:
        print("Lot Number Invalid")
    else:
        print(charge)






    