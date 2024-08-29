students = {}

def add_student(stu_id, name, s_class, grades, height, weight, pre_sport):
    if stu_id in students:
        print(f"Student with ID {stu_id} already exists.")
    else:
        students[stu_id] = {
            'name': name,
            'class': s_class,
            'grades': grades,
            'height': height,
            'weight': weight,
            'pre_sport': pre_sport
        }
        print(f"Student {name} added successfully.")

def update_grades(stu_id, new_grades):
    if stu_id in students:
        students[stu_id]['grades'] = new_grades
        print(f"New grades for student ID {stu_id} updated successfully.")
    else:
        print(f"Student ID {stu_id} not found.")

def calculate_average(stu_id):
    if stu_id in students:
        grades = students[stu_id]['grades']
        if grades:
            average = sum(grades) / len(grades)
            return average
        else:
            return 0
    else:
        print(f"Student with ID {stu_id} not found.")
        return None

def recommend_sport(strength):
    if strength <= 20:
        return "Chess is a good option for you."
    elif strength <= 40:
        return "Javelin throw is a good option for you."
    elif strength <= 60:
        return "Cricket is a good option for you."
    else:
        return "Football is a good option for you."

add_student("001", "Ram", "6", [85, 92, 50], 170, 65, "Football")
add_student("002", "Bob", "7", [60, 79, 84], 175, 70, "Cricket")
add_student("003", "Charlie", "10", [91, 89, 100], 180, 80, "Chess")

update_grades("001", [88, 90, 85])

generate_student_report()

strength = 45
print(f"Recommended sport based on strength ({strength}): {recommend_sport(strength)}")
