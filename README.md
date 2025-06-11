# Smart-Electronic-Voting-Machine-using-Fingerprint-Recognition
# 🗳️ Smart Electronic Voting Machine using Fingerprint Recognition

This project is a **biometric-based electronic voting system** developed using **Arduino UNO** and a **fingerprint sensor**. It authenticates users via fingerprint recognition, allowing them to vote securely. It prevents duplicate voting and displays results in real time.

---

## 🔧 Features

- ✅ Fingerprint-based voter authentication
- 🧠 Arduino-powered secure logic and memory
- 📟 LCD-based voting guidance and result display
- 🔒 Duplicate vote prevention logic
- 🔊 Buzzer feedback for actions (vote cast, duplicate warning)
- 🗳️ Vote count display using a dedicated result button
- 🌐 Extendable to cloud-based or blockchain-secure voting

---

## 📷 Hardware Used

| Component             | Description                                      |
|----------------------|--------------------------------------------------|
| Arduino UNO          | Main microcontroller used for logic and control |
| Fingerprint Sensor   | Used to identify and authenticate voters         |
| 16x2 LCD Display     | Displays instructions, warnings, and results     |
| Push Buttons (x4)    | Represents different political parties           |
| Buzzer               | Indicates success/failure (e.g., duplicate vote) |
| Jumper Wires         | Direct connections between components            |
| Mounting Board       | Components mounted directly (no breadboard used) |

> **Note:** A breadboard was **not** used. All connections were made directly using jumper wires on a mounting base.

---

## 📁 Project Structure

```bash
Smart-Electronic-Voting-Machine/
├── enrollment_code.ino            # Code to enroll fingerprints
├── With_Result_button.ino         # Main voting logic with result button
├── Mini-Project_Report.docx       # Full documentation with figures and description
├── images/
│   ├── project_setup.jpg          # Image showing final setup
│   ├── fingerprint_enroll.jpg     # Fingerprint module during enrollment
│   ├── result_screen.jpg          # LCD displaying result
│   └── duplicate_warning.jpg      # Warning shown on duplicate vote attempt
├── README.md                      # This file
└── LICENSE                        # (Optional) Project license
