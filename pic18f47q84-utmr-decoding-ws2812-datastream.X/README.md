**UTMR Timing**

- Fosc = 64 MHz
- TUCLK = Fosc = 64 MHz
- 1 timer tick = 1/Fosc = 15.625ns

**WS2812 Timing**

- Freq = 800 ksps = 1.25us ~600ns         ==> 80 timer clocks
- 2x Freq = 1.6MHz = 1600 ksps = 625ns    ==> 40 timer clocks

- T0H = 500ns ~150ns (350-650ns)          ==> 32(22-41)  timer clocks
- T0L = 800ns ~150ns
- 30% DC @800kHz = 375ns                  ==> 24 timer clocks

- T1H = 700ns ~150ns (550-850ns)          ==> 44 (35-54) timer clocks
- T1L = 600ns ~150ns
- 50% DC @800kHz = 625ns                  ==> 40 timer clocks

- TRST > 50us                             ==> 3200 timer clocks
- 52us                                    ==> 3328 timer clocks