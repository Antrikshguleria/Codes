import sys
from PyQt5.QtWidgets import QApplication, QMainWindow, QLabel, QLineEdit, QPushButton

class DirectivityCalculator(QMainWindow):
    def __init__(self):
        super().__init__()

        self.init_ui()

    def init_ui(self):
        self.setWindowTitle('Directivity Calculator')

        self.label_e_field = QLabel('Enter Electric Field (E):', self)
        self.label_e_field.move(20, 20)
        self.e_field_input = QLineEdit(self)
        self.e_field_input.move(200, 20)

        self.label_h_field = QLabel('Enter Magnetic Field (H):', self)
        self.label_h_field.move(20, 60)
        self.h_field_input = QLineEdit(self)
        self.h_field_input.move(200, 60)

        self.calculate_button = QPushButton('Calculate Directivity', self)
        self.calculate_button.move(100, 100)
        self.calculate_button.clicked.connect(self.calculate_directivity)

        self.result_label = QLabel('Directivity: ', self)
        self.result_label.move(20, 140)

        self.setGeometry(100, 100, 350, 180)

    def calculate_directivity(self):
        e_field = float(self.e_field_input.text())
        h_field = float(self.h_field_input.text())

        # Perform directivity calculation (replace with actual calculation)
        directivity = e_field / h_field

        self.result_label.setText(f'Directivity: {directivity:.2f}')

def main():
    app = QApplication(sys.argv)
    window = DirectivityCalculator()
    window.show()
    sys.exit(app.exec_())

if __name__ == '__main__':
    main()
