#Final3


class Vehicle:
    def __init__(self, make: str, model: str, year: int):
        self.make: str = make
        self.model: str = model
        self.year: int = year
        self.odometer_reading: int = 0

    def get_descriptive_name(self) -> str:
        return (self.model)

    def read_odometer(self) -> None:
        print("Odometer reading: \n")
        print (self.odometer_reading)

    def update_odometer(self, mileage: int) -> None:
        if mileage >= self.odometer_reading:
            self.odometer_reading = mileage
        else:
            print("You can't roll back an odometer!")

    def increment_odometer(self, miles: int) -> None:
        self.odometer_reading += miles


class Car(Vehicle):
    def __init__(self, make: str, model: str, year: int):
        Vehicle.__init__(self,make, model, year)
        self.fuel_capacity: int = 500
        self.fuel_level: int = 0

    def fill_tank(self) -> None:
        self.fuel_level = self.fuel_capacity
        print("Fuel tank is now full.")


def main() -> None:
    cars: list[Car] = [
        Car("Audi", "A4", 2019), Car("BMW", "X5", 2020), Car("Tesla", "Model S", 2021)]

    # Looping through each car
    l: int 
    for l in range(2):
        car: Car = cars[l]
        print(car.get_descriptive_name())
        car.read_odometer()
        ast: list[int] = [12,-56,730]
        # Using a while loop to update odometer
        while True:
            new_mileage: int
            n: int
            for n in range(3):
                new_mileage = ast[n]
                if new_mileage < 0:
                    print("Mileage can't be negative. Try again.")
                    continue
                car.update_odometer(new_mileage)
                car.read_odometer()
            break
        
        # Using a for loop to increment odometer
        i: int
        for i in range(2):
            car.increment_odometer(50*i)
            car.read_odometer()
        
        # Using an if statement to check fuel level
        if car.fuel_level == 0:
            car.fill_tank()
            car.read_odometer()
            car.increment_odometer(100)  # Assuming driving after filling tank
            car.read_odometer()
        
        # Using a break statement to exit the loop prematurely
        if car.model == "X5":
            print("Encountered BMW X5, exiting loop.")
            break


if __name__ == "__main__":
    main()
