from random import choice
questions = ["Why is the sky blue?","Why is there a face on the moon?","Where are all the dinosaurs?"]
question = choice(questions)
answer = input(question).strip().lower()
while answer != "just because" :
    answer = input("Why? : ").strip().lower()
    
