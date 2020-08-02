
class Doctor:

    def __init__(self,doctorId,doctorName,specialization,consulationFee):
        self.doctorId = doctorId
        self.doctorName = doctorName
        self.specialization = specialization
        self.consulationFee = consulationFee



class Hospital(Doctor):

    def __init__(self,doctorDB):
        self.doctorDB = doctorDB

    def searchByDoctorName(self,name):
        all_lis = self.doctorDB.values()
        lis = []
        for obj in all_lis:
            if obj.doctorName == name:
                lis.append(obj)
        if lis == []:
            return None
        else:
            return lis
         
    def calculateConsulationFeeBySpecialization(self,spec):
        summer = 0
        checker0 = False
        for obj in self.doctorDB.values():
            if obj.specialization == spec:
                checker0 = True
                summer += obj.consulationFee

        if checker0:
            return summer,True
        else:
            return 0,False

    
    def printer(self):
        print(self.doctorDB)
        
    

def main():
    num = int(input("Enter number of inputs : "))
    docData = {}
    for i in range(num):
        docId = int(input())
        docName = input()
        docSpec = input()
        docFee = int(input())
        docData.update({i : Doctor(docId,docName,docSpec,docFee)})

    hosObj = Hospital(docData)
    ToSearch = input()
    SpecSearch = input()
    print(f"Searching for dotor : {ToSearch} and Specialisation fee sum : {SpecSearch}")
    fn1 = hosObj.searchByDoctorName(ToSearch)
    if fn1 == None:
        print("No doctor exists with the given Doctor Name")
    else:
        for ele in fn1:
            print(ele.doctorId)
            print(ele.doctorName)
            print(ele.specialization)
            print(ele.consulationFee)

    fn2,boolean = hosObj.calculateConsulationFeeBySpecialization(SpecSearch)
    
    if boolean:
        print("Total sum of consultation :",fn2)
    else:
        print("No Doctor with the given specification")

    

main()