create_clock -name clk_in -period 20.000 [get_ports CLOCK_50]

derive_pll_clocks

derive_clock_uncertainty
