use std::io;

struct Student {
    student_name: String,
    student_id: u32,
    grade: f32,
}

fn get_input(prompt: &str) -> String {
    let mut input = String::new();

    println!("{}", prompt);

    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read input");

    input.trim().to_string()
}

fn is_valid_grade(grade: f32) -> bool {
    grade >= 0.0 && grade <= 110.0
}

fn update_grade(student: &mut Student, new_grade: f32) {
    student.grade = new_grade;
}

fn display_report(student: &Student, original_grade: f32) {
    println!("\n----------------------------------------");
    println!("Hillsborough County School District");
    println!("Student Grade Report Version 1.0");
    println!("----------------------------------------");

    println!("Student ID     : {}", student.student_id);
    println!("Student Name   : {}", student.student_name);
    println!("Original Grade : {:.2}", original_grade);
    println!("Current Grade  : {:.2}", student.grade);

    println!("----------------------------------------");
}

fn main() {
    let student_name = get_input("Enter student name:");

    let student_id: u32 = match get_input("Enter student ID:").parse() {
        Ok(value) => value,
        Err(_) => {
            println!("Invalid student ID.");
            return;
        }
    };

    let grade: f32 = match get_input("Enter current grade:").parse() {
        Ok(value) => value,
        Err(_) => {
            println!("Invalid grade.");
            return;
        }
    };

    if !is_valid_grade(grade) {
        println!("Grade must be between 0 and 110.");
        return;
    }

    let mut student = Student {
        student_name,
        student_id,
        grade,
    };

    let original_grade = student.grade;

    loop {
        let new_grade: f32 = match get_input("Enter updated grade:").parse() {
            Ok(value) => value,
            Err(_) => {
                println!("Invalid grade entered.");
                continue;
            }
        };

        if !is_valid_grade(new_grade) {
            println!("Grade must be between 0 and 110.");
            continue;
        }

        update_grade(&mut student, new_grade);

        println!("\nGrade updated successfully.");

        display_report(&student, original_grade);

        let choice = get_input("Update again? (y/n)");

        if choice.to_lowercase() != "y" {
            break;
        }
    }

    println!("\nProgram complete.");
}
