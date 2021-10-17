known_users=["Ross","Rachel","Monica","Chandler","Joey","Phoebe","Emma","Ben"]
while True :
    print("Hi! My name is Rohit")
    name=input("What is your name?: ").strip().capitalize()
    if name in known_users :
        print("Hello! {}".format(name))
        remove=input("Would you like to be removed from the system(y/n) ?: ").strip().lower()
        if remove=="y":
            known_users.remove(name)
        elif remove=="n":
            print("No problem,I didn't want you to leave anyway")
    else :
        print("I don't think I've met you yet {}".format(name))
        add_me=input("Would you like to be added to the system(y/n) ? : ").lower()
        if add_me=="y":
            known_users.append(name)
        elif add_me=="n":
            print("Okay, See you around")

            
            
    
    
