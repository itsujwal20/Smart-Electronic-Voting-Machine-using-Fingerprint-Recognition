# 🗳️ Smart Electronic Voting Machine using Fingerprint Recognition

A secure, Arduino-based biometric voting system using fingerprint authentication to ensure one person, one vote — with real-time result display and prevention of duplicate votes.

---

## 🔧 Features

- ✅ Fingerprint-based voter verification
- 📟 LCD screen for vote guidance and result
- 🔒 Duplicate vote protection
- 🔊 Buzzer alerts for actions
- 🗳️ Button-based voting for parties
- 💡 Power-efficient, Arduino UNO-based implementation
- 📂 Modular code: separate enrollment and voting logic

---

## 🧰 Hardware Used

| Component             | Purpose                                     |
|----------------------|---------------------------------------------|
| Arduino UNO          | Core microcontroller                        |
| Fingerprint Sensor   | Biometric voter identification              |
| 16x2 LCD Display     | User interface for status and result        |
| Push Buttons (x4)    | To vote for specific candidates/parties     |
| Buzzer               | Feedback (vote confirmed / duplicate)       |
| Jumper Wires         | Wiring between modules                      |
| Fixed Mounting Board | Physical assembly base (no breadboard used) |

---

## 📁 Project Structure

```bash
.
├── Voting.ino                          # Final integrated code for voting
├── enrollment_code.ino                # Fingerprint enrollment code
├── README.md                          # Project documentation (this file)
├── documents/
│   ├── Report - Smart Electronic Voting Machine Using Fingerprint Recognition.pdf
│   └── PPT - Smart Electronic Voting Machine Using Fingerprint Recognition.pdf
├── images/
│   ├── Image_1.jpg                    # Voting setup or fingerprint scan
│   └── Image_2.jpg                    # LCD result or warning screen
