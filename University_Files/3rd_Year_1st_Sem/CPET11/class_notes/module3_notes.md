1. Support Circuit Designs - extra electronic circuits that work together with the microcontroller to help it run better and smoothly. An example of this are the regulated power supply.

2. Basic Ohm's law formulas:
    terms use:
        E (voltage=volts), I (current=ampere), P (power=watts), R (resistance=ohms), Vm (voltage peak)
    E = IR
    I = E/R
    R = E/I
    P = EI
    P = I²R
    P = E²/R

3. Regulated Power Supply - A dc (direct current) power supply that provides a stable, regulated power to the mcu and its system periphirals.
    Figure 1: DC Regulated Power supply Design
        - This figure explains how the AC (alternatig current) gets filtered out and transforms into a dc (direct current). Starting from the step-down transformer, to a rectifier (converts ac into an unfiltered dc "pulsating" by allowing the flow of current into one direction only), to a filter (using capacitor to smooth out the pulsating dc, this happens because the capacitor have the ability to store an energy and then releases it if it experiences a voltage dip (low voltage shit in a pulsating dc -_-_-_ (_) dip). By storing the energy and releasing it when the voltage happens, the dip will be filtered out because the capacitor only releases a certain stable voltage every dip), to the IC regulator (which decides which voltage to use 5V etc.), into the load (the actual component being powered up).
    Figure 2: DC Regulated Power supply Design schematic diagram
        - Basically the schematic diagram of the aforementioned design.

4. Design Consideration 
    - Determine the load(device) first and list its required I(current). After figuring out your load, you should also list Vo (voltage output that you want as a supply). Using the required current of your load and the Vo you have used, you can now calculate the resistance needed for your load (para hindi masira) using the formula R = V/I. Or you can just design a circuit na ang output ay pasok doon sa load na gagamitin mo (wag kang sbapn).

    - Check the power dissipation of the load. Power dissipation is the heat that the load will release as it uses power. Compute it using the formula P = VI. The actual component must have a power rating higher than the calculated value so it doesn't overheat. (apply for resistor and other components).
    
    - Transformer Voltage Rating. Provide a high enough voltage supply for your desired dc output. Para maiwasan ang hindi pag meet ng desired dc, kasi yung power nyan ay nababawasan as it passes different kind of components. Example: if you want a 5 volts output, then you should get atleast a 12 volts step down or 24 volts step-down transormer. You can check the trasformer datasheet to check if your transformer meet the dc output of your design.

    - Transformer current rating. The required I(current) of the transformer should be equal or higher than the computed Io of the load.

    - Peak voltage of ac. You should find the peak voltage of the ac because usually the 12 volts that you see is just the rms. Its important to get the voltage peak because this is the true value that the capacitor uses to charge itself up, meaning that to get your actual desired output you need to get the true value (peak voltage) of the transformer. To calculate this shit we have the formula Vm = Vmp(rms voltage) x √2.  
    
    - Rectifier voltage drop. Add all the voltage of each rectifier that you are using (diode), usually a diode have a 0.7 voltage (see datasheet for accurate voltage). After that list it as Vk then that is the voltage drop after rectifying
    - Calculate the DC output voltage. Using the Vk (voltage drop after rectification) and the Vm (voltage peak), calculate the output voltage after it passes in the rectifier. Here is the formula:
        Full-wave rectifier:
            Vdc = 0.636 x (Vm - 2Vk)
        Half-wave rectifier:
            Vdc = 0.318 x (Vm-Vk)
    - Filter Capacitor. Use this formula to get the value of the capacitor for your design: C = I x T / V.
        I = Current
        T = Time between cycles
            Full wave: 8.33ms (1/120 hz)
            half wave: 16.64ms (1/60 hz)
        V = Acceptable ripple voltage (vripple - basically what ripple you allow to stay in the output). This is important because some electornics need big and smaller ripples yeah. 
        Note: Bigger C less ripple.
    - Ripple Voltage (Vriple). Ideally you want 0.5dc ripple for a clean dc supply. There is also a forula for this shit.
        Formula: Vripple = Vdc x (1 - e^(-T / (RL x C)))
        This equation shows that:
            Larger RL (higher load resistance) -> less ripple.
            Larger C (bigger capacitor) -> less ripple.
    - Frequency. Ripple frequency depends on the rectification type.
        half wave - Ripple Frequency = Input Frequency (60hz)
        full wave - Ripple Frequency = 2 x input frequency
        A higher frequency makes filtering easier.
    - For fixed Regulator ICs (e.g, 7805, 7812)
        - A fixed regulator outputs one specific voltage (5V,9V etc.)
        - Check the pin configuration Vin, G, Vo (output).
        - Ensure VMP is >= Vin requirements. Vmp (peak voltage after rectification). Regulators need "headroom" (dropout voltage) to keep the output stable.    
        - Follow recommended component in the datasheet or calculate for the values.
        - Understand output ratings. Datasheet list Vmin, Vtypical, and Vmax for the output:
            Vmin = lowest guaranteed output under worst conditions.
            Vtypical = The normal/average output.
            Vmax = the highest allowed output.
            Each value is given with specific test condition.
            Imin/Itypical/Imax = load current.
    - For adjustable Regulator ICs
        - An adjustable regulator lets you adjust the voltage (within limits).
        - Check the pin configuration Vin, Vadj, Vo 
        - Ensure Vmp >= Vin
        - Follow datasheet optimization components, if not calculate.
        - Output capacitor usually have 1 microfarad to 1000 microfarad
        - Output Voltage formula 
            - Vo = Vref (1+R2/R1) + (Iadj x R2)
            - Vref is typically 1.25V
            - Iadj - current of adj
    - For adapter / Charger Designs
        - The Vo and Io of the adaptor substitute the Vm and Im parameters of the transformer.
        - Additional half-wave or full-wave rectifier circuits can be used and follow the same design considerations as using the conventional transformer method.

5. Sample design -> tignan sa module 3 drive.









