use std::io;

struct Patient {
    patient_id: u32,
    patient_name: String,
    temperature: f32,
    systolic: u32,
    diastolic: u32,
}

fn get_input(prompt: &str) -> String {
    let mut input = String::new();

    println!("{}", prompt);

    io::stdin()
        .read_line(&mut input)
        .expect("Failed to read input");

    input.trim().to_string()
}

fn patient_id_exists(patients: &Vec<Patient>, id: u32) -> bool {
    for patient in patients {
        if patient.patient_id == id {
            return true;
        }
    }

    false
}

fn main() {
    let mut patients: Vec<Patient> = Vec::new();

    println!("Enter patient information");

    let number_of_patients = 10;

    for i in 0..number_of_patients {
        println!("\nPatient {}", i + 1);

        let patient_id: u32;

        loop {
            let input_id = get_input("Patient ID:");

            match input_id.parse::<u32>() {
                Ok(id) => {
                    if patient_id_exists(&patients, id) {
                        println!("Patient ID already exists. Enter a different ID.");
                    } else {
                        patient_id = id;
                        break;
                    }
                }
                Err(_) => {
                    println!("Invalid ID. Try again.");
                }
            }
        }

        let patient_name = get_input("Patient Name:");

        let temperature: f32 = get_input("Temperature (F):")
            .parse()
            .expect("Invalid temperature");

        let systolic: u32 = get_input("Systolic Blood Pressure:")
            .parse()
            .expect("Invalid systolic value");

        let diastolic: u32 = get_input("Diastolic Blood Pressure:")
            .parse()
            .expect("Invalid diastolic value");

        patients.push(Patient {
            patient_id,
            patient_name,
            temperature,
            systolic,
            diastolic,
        });
    }

    println!("\nAll patient records entered successfully.");

    let mut start: usize = get_input("Patient list start:")
        .parse()
        .expect("Invalid start value");

    let mut finish: usize = get_input("Patient list finish:")
        .parse()
        .expect("Invalid finish value");

    if start < 1 {
        start = 1;
    }

    if start > patients.len() {
        println!("Invalid range.");
        return;
    }

    if finish > patients.len() {
        finish = patients.len();
    }

    if start > finish {
        println!("Invalid range.");
        return;
    }

    let selected_patients = &patients[start - 1..finish];

    let mut total_temperature = 0.0;

    for patient in &patients {
        total_temperature += patient.temperature;
    }

    let average_temperature = total_temperature / patients.len() as f32;

    println!("\n----------------------------------------");
    println!("Memorial Community Hospital");
    println!("Patient Summary Report");
    println!("----------------------------------------");

    println!("Total Patients Entered: {}", patients.len());

    for patient in selected_patients {
        println!("----------------------------------------");

        println!("Patient ID: {}", patient.patient_id);

        println!("Name: {}", patient.patient_name);

        println!("Temperature: {:.1} F", patient.temperature);

        println!("Blood Pressure: {}/{}", patient.systolic, patient.diastolic);
    }

    println!("----------------------------------------");

    println!("Average Temperature: {:.2} F", average_temperature);

    println!("Report completed successfully.");
}
