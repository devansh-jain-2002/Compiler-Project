#Final 4
def intro():
    print("Welcome to the Choose Your Own Adventure Game!")
  
    print("You find yourself standing at a crossroads...")

    print("You have to make choices to proceed. Let's see where they take you.")


def crossroads()->str:
    print("You're at a crossroads.")

    print("To your left is a dark forest.")

    print("To your right is a narrow path leading up a hill.")

    print("Straight ahead is a small town.")


    while True:
        choice: str = "left"
        if choice == 'left':
            return choice
        else:
            print("Invalid choice. Please choose left, right, or straight.")

def dark_forest()-> str:
    print("You enter the dark forest.")

    print("The trees loom overhead, blocking out much of the sunlight.")

    # print("You hear strange noises all around you.")
    
    print("Do you continue deeper into the forest or turn back?")


    while True:
        choice: str = 'continue'
        if choice == 'continue':
            print("You venture deeper into the forest...")

            # print("Suddenly, you stumble upon a hidden treasure chest!")

            print("Congratulations! You found treasure!")
            return "treasure"
        elif choice == 'turn back':
            print("You decide to turn back...")

            print("You return to the crossroads.")
            return "Nope"
        else:
            print("Invalid choice. Please choose continue or turn back.")

def hill_path() -> str:
    print("You take the narrow path leading up the hill.")
 
    print("The path is steep and winding.") #Comment here for testing

    # print("As you climb higher, the view becomes more breathtaking.")

    print("Do you continue climbing or descend back down")


    while True:
        choice:str = 'descend'
        if choice == 'climb':
            print("You continue climbing...")

            print("At the top of the hill, you find an ancient temple!")

            print("You explore the temple and discover hidden artifacts.")

            print("Congratulations! You found ancient treasures!")
            return "treasure"
        elif choice == 'descend':
            print("You decide to descend...")

            print("You return to the crossroads.")
            return "Nope"
        else:
            print("Invalid choice. Please choose climb or descend.")

def town() -> str:
    print("You arrive at the small town.")

    print("The town is bustling with activity.")

    print("There are shops, inns, and people going about their daily lives.")

    print("Do you explore the town or head back to the crossroads?")


    while True:
        choice: str = 'explore'
        if choice == 'explore':
            print("You explore the town...")

            print("You meet friendly locals and learn about the town's history.")

            print("After a pleasant time, you decide to head back to the crossroads.")
            return "Noi"
        elif choice == 'head back':
            print("You decide to head back to the crossroads...")

            print("You return to the crossroads.")
            return "Nope"
        else:
            print("Invalid choice. Please choose explore or head back.")

def main():
    intro()
    
    while True:
        choice: str = crossroads()
        result: str
        if choice == 'left':
            result = dark_forest()
            if result == "treasure":
                print("You have acquired valuable treasure!")
                break
        elif choice == 'right':
            result = hill_path()
            if result == "treasure":
                print("You have discovered ancient treasures!")
                break
        elif choice == 'straight':
            town()

    print("Thanks for playing!")

if __name__ == "__main__":
    main()
