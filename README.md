<br/>
<p align="center">
  <a href="https://github.com/dhamuvkl/TempGuard">
    <img src="https://cdn4.iconfinder.com/data/icons/logos-and-brands/512/273_Readme_logo-512.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">TempGuard</h3>

  <p align="center">
    A sophisticated temperature control system designed for industrial heating applications. It employs a unique approach by utilizing an IRFZ44N MOSFET as a temperature sensor!
    <br/>
    <br/>
  </p>
</p>

![Contributors](https://img.shields.io/github/contributors/dhamuvkl/TempGuard?color=dark-green) ![Stargazers](https://img.shields.io/github/stars/dhamuvkl/TempGuard?style=social) ![Issues](https://img.shields.io/github/issues/dhamuvkl/TempGuard) ![License](https://img.shields.io/github/license/dhamuvkl/TempGuard) 

## Table Of Contents

* [About the Project](#about-the-project)
* [Key Features](#key-features)
* [Technologies Used](#technologies-used)
* [Schematics & Fabrication](#schematics-and-fabrication)
* [Roadmap](#roadmap)
* [Contributing](#contributing)
* [License](#license)
* [Struggles Faced during Development](#struggles-faced-during-development)
* [Author](#author)


## About The Project

![Screen Shot](https://dharageshtech.wordpress.com/wp-content/uploads/2024/06/tempguard-1-1.png?strip=info&w=1800)

**TempGuard** is a sophisticated temperature control system designed for industrial heating applications. It employs a unique approach by utilizing an IRFZ44N MOSFET as a temperature sensor, enabling precise temperature measurements. This innovative system, driven by a BluePill microcontroller (STM32F103C8T6), ensures heating elements operate within desired temperature ranges. Additionally, it features a user interface for seamless adjustments.

##  Key Features: 

* **Overheating Prevention:** TempGuard prevents heating elements from overheating and potential damage, thus extending their operational lifespan.
  
* **Energy Efficiency:** By maintaining an optimal temperature range, the system reduces energy consumption, ultimately lowering electricity bills.  


* **Uniform Heating:** Ensures consistent temperature levels, eliminating issues associated with uneven heating, and thereby enhancing industrial processes.  


* **Versatility:** TempGuard's adaptability extends beyond industrial heating systems, making it suitable for a wide range of applications requiring precise temperature control.  

* **Robust Performance:** Engineered to function reliably under extreme temperature conditions, both in hot and cold environments.

  ![Screen Shot](https://dharageshtech.files.wordpress.com/2023/09/1694341662716.jpg?strip=info&w=1800)

## Technologies Used:

* **IRFZ44N MOSFET as Temperature Sensor:** This unconventional choice allows for accurate temperature measurements, enhancing the control of heating elements.
  

* **BluePill Microcontroller (STM32F103C8T6):** Responsible for crucial tasks including measuring MOSFET temperature values, controlling the relay board, and obtaining user-defined temperature settings.  


* **Relay System:** Vital for regulating the heating element based on the measured temperature values.  


* **User Interface with Switch:** Enables users to toggle between two predefined temperature settings, adding flexibility to the system.  

## Schematics and Fabrication 
![Screen Shot](https://dharageshtech.wordpress.com/wp-content/uploads/2024/06/tempguard-sh-0.png?strip=info&w=1800)
![Screen Shot](https://dharageshtech.wordpress.com/wp-content/uploads/2024/06/tempguard-sh-1.png?strip=info&w=1800)
![Screen Shot](https://dharageshtech.wordpress.com/wp-content/uploads/2024/06/tempguard-sh-2.png?strip=info&w=1800)
![Screen Shot](https://dharageshtech.wordpress.com/wp-content/uploads/2024/06/tempguard-sh-3.png?strip=info&w=1800)
![Screen Shot](https://dharageshtech.wordpress.com/wp-content/uploads/2024/06/tempguard-sh-4.png?strip=info&w=1800)
![Screen Shot](https://dharageshtech.wordpress.com/wp-content/uploads/2024/06/tempguard-2-1.png?strip=info&w=1800)
![Screen Shot](https://dharageshtech.wordpress.com/wp-content/uploads/2024/06/tempguard-3-1.png?strip=info&w=1800)
![Screen Shot](https://dharageshtech.wordpress.com/wp-content/uploads/2024/06/tempguard-4-1.png?strip=info&w=1800)
![Screen Shot](https://dharageshtech.wordpress.com/wp-content/uploads/2024/06/tempguard-5-1.png?strip=info&w=1800)
![Screen Shot](https://dharageshtech.wordpress.com/wp-content/uploads/2024/06/tempguard-6-1.png?strip=info&w=1800)
![Screen Shot](https://dharageshtech.wordpress.com/wp-content/uploads/2024/06/tempguard-7-1.png?strip=info&w=1800)
![Screen Shot](https://dharageshtech.wordpress.com/wp-content/uploads/2024/06/tempguard-8-1.png?strip=info&w=1800)
![Screen Shot](https://dharageshtech.wordpress.com/wp-content/uploads/2024/06/tempguard-9-1.png?strip=info&w=1800)


## Roadmap

See the [open issues](https://github.com/dhamuvkl/TempGuard/issues) for a list of proposed features (and known issues).

## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.
* If you have suggestions for adding or removing projects, feel free to [open an issue](https://github.com/dhamuvkl/TempGuard/issues/new) to discuss it, or directly create a pull request after you edit the *README.md* file with necessary changes.
* Please make sure you check your spelling and grammar.
* Create individual PR for each suggestion.

## Struggles Faced during Development:
<img align="right" alt="coding" width="500" src="https://dharageshtech.files.wordpress.com/2023/09/img_20230616_124905.jpg?strip=info&w=1800">

* **Analog Prototype with OP-AMP (LM358):** The initial version of the prototype relied on an analog design, utilizing an LM358 OP-AMP in hysteresis mode. However, this approach proved sensitive to Electromagnetic Interference (EMI) during field tests.
  

* **EMI Sensitivity:** The analog design was susceptible to EMI, especially from electrical noise in the grid. This led to erratic switching of temperature set values, making the system unreliable.  


* **Transition to Digital Design:** To address the EMI sensitivity issue, a significant shift was made towards a digital approach. This involved integrating the BluePill microcontroller (STM32F103C8T6) to bring stability and robustness to the system's operation.

## License

Distributed under the MIT License. See [LICENSE](https://github.com/dhamuvkl/TempGuard/blob/main/LICENSE.md) for more information.

## Author

* **Dharageswaran S** - *Electronics Enthusiast | Innovator | Tech Visionary* - [Dharageswaran S](https://github.com/DhamuVkl/) - *Owner *

