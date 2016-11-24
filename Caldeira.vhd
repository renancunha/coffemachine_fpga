-- Copyright (C) 1991-2013 Altera Corporation
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, Altera MegaCore Function License 
-- Agreement, or other applicable license agreement, including, 
-- without limitation, that your use is for the sole purpose of 
-- programming logic devices manufactured by Altera and sold by 
-- Altera or its authorized distributors.  Please refer to the 
-- applicable agreement for further details.

library ieee;
use ieee.std_logic_1164.all;
library altera;
use altera.altera_syn_attributes.all;

entity Caldeira is
	port
	(
-- {ALTERA_IO_BEGIN} DO NOT REMOVE THIS LINE!

		BUTTON : in std_logic_vector(2 downto 0);
		CLOCK_50 : in std_logic;
		CLOCK_50_2 : in std_logic;
		DRAM_ADDR : out std_logic_vector(12 downto 0);
		DRAM_BA_0 : out std_logic;
		DRAM_BA_1 : out std_logic;
		DRAM_CAS_N : out std_logic;
		DRAM_CKE : out std_logic;
		DRAM_CLK : out std_logic;
		DRAM_CS_N : out std_logic;
		DRAM_DQ : inout std_logic_vector(15 downto 0);
		DRAM_LDQM : out std_logic;
		DRAM_RAS_N : out std_logic;
		DRAM_UDQM : out std_logic;
		DRAM_WE_N : out std_logic;
		FL_ADDR : out std_logic_vector(21 downto 0);
		FL_BYTE_N : out std_logic;
		FL_CE_N : out std_logic;
		FL_DQ : inout std_logic_vector(15 downto 0);
		FL_OE_N : out std_logic;
		FL_RST_N : out std_logic;
		FL_RY : in std_logic;
		FL_WE_N : out std_logic;
		FL_WP_N : out std_logic;
		GPIO0_CLKIN : in std_logic_vector(1 downto 0);
		GPIO0_CLKOUT : out std_logic_vector(1 downto 0);
		GPIO0_D : inout std_logic_vector(31 downto 0);
		GPIO1_CLKIN : in std_logic_vector(1 downto 0);
		GPIO1_CLKOUT : out std_logic_vector(1 downto 0);
		GPIO1_D : inout std_logic_vector(31 downto 0);
		HEX0_D : out std_logic_vector(6 downto 0);
		HEX0_DP : out std_logic;
		HEX1_D : out std_logic_vector(6 downto 0);
		HEX1_DP : out std_logic;
		HEX2_D : out std_logic_vector(6 downto 0);
		HEX2_DP : out std_logic;
		HEX3_D : out std_logic_vector(6 downto 0);
		HEX3_DP : out std_logic;
		LCD_BLON : out std_logic;
		LCD_DATA : inout std_logic_vector(7 downto 0);
		LCD_EN : out std_logic;
		LCD_RS : out std_logic;
		LCD_RW : out std_logic;
		LEDG : out std_logic_vector(9 downto 0);
		PS2_KBCLK : inout std_logic;
		PS2_KBDAT : inout std_logic;
		PS2_MSCLK : inout std_logic;
		PS2_MSDAT : inout std_logic;
		SD_CLK : out std_logic;
		SD_CMD : inout std_logic;
		SD_DAT : inout std_logic;
		SD_WP_N : in std_logic;
		SW : in std_logic_vector(9 downto 0);
		UART_CTS : out std_logic;
		UART_RTS : in std_logic;
		UART_RXD : in std_logic;
		UART_TXD : out std_logic--;
--		VGA_B : out std_logic_vector(3 downto 0);
--		VGA_G : out std_logic_vector(3 downto 0);
--		VGA_HS : out std_logic;
--		VGA_R : out std_logic_vector(3 downto 0);
--		VGA_VS : out std_logic

-- {ALTERA_IO_END} DO NOT REMOVE THIS LINE!

	);

-- {ALTERA_ATTRIBUTE_BEGIN} DO NOT REMOVE THIS LINE!
-- {ALTERA_ATTRIBUTE_END} DO NOT REMOVE THIS LINE!
end Caldeira;

architecture ppl_type of Caldeira is

-- {ALTERA_COMPONENTS_BEGIN} DO NOT REMOVE THIS LINE!
-- {ALTERA_COMPONENTS_END} DO NOT REMOVE THIS LINE!
--    component CPU_NIOS is
--        port (
--            i_switch_export : in  std_logic_vector(9 downto 0) := (others => 'X'); -- export
--            o_led_export    : out std_logic_vector(9 downto 0);                    -- export
--            clk_clk         : in  std_logic                    := 'X'              -- clk
--        );
--    end component CPU_NIOS;
    component CPU_NIOS is
        port (
            i_switch_export   : in  std_logic_vector(9 downto 0) := (others => 'X'); -- export
            o_led_export      : out std_logic_vector(9 downto 0);                    -- export
            clk_clk           : in  std_logic                    := 'X';             -- clk
            o_hex0_export     : out std_logic_vector(6 downto 0);                    -- export
            o_hex1_export     : out std_logic_vector(6 downto 0);                    -- export
            o_hex2_export     : out std_logic_vector(6 downto 0);                    -- export
            o_hex3_export     : out std_logic_vector(6 downto 0);                    -- export
            i_preparar_export : in  std_logic                    := 'X';             -- export
            i_repor_export    : in  std_logic                    := 'X'              -- export
        );
    end component CPU_NIOS;
begin
-- {ALTERA_INSTANTIATION_BEGIN} DO NOT REMOVE THIS LINE!
-- {ALTERA_INSTANTIATION_END} DO NOT REMOVE THIS LINE!
--    u0 : component CPU_NIOS
--        port map (
--            i_switch_export => SW, -- i_switch.export
--            o_led_export    => LEDG,    --    o_led.export
--            clk_clk         => CLOCK_50          --      clk.clk
--        );
--
--	u0 : component CPU_NIOS
--        port map (
--            i_switch_export => SW, -- i_switch.export
--            o_led_export    => LEDG,    --    o_led.export
--            clk_clk         => CLOCK_50,         --      clk.clk
--            o_hex0_export   => HEX0_D    --   o_hex0.export
--        );
	u0 : component CPU_NIOS
        port map (
            i_switch_export   => SW,   --   i_switch.export
            o_led_export      => LEDG,      --      o_led.export
            clk_clk           => CLOCK_50,           --        clk.clk
            o_hex0_export     => HEX0_D,     --     o_hex0.export
            o_hex1_export     => HEX1_D,     --     o_hex1.export
            o_hex2_export     => HEX2_D,     --     o_hex2.export
            o_hex3_export     => HEX3_D,     --     o_hex3.export
            i_preparar_export => BUTTON(0), -- i_preparar.export
            i_repor_export    => BUTTON(1)     --    i_repor.export
        );
		  
	-- Apaga os pontos nos displays de 7 segmentos.
	HEX0_DP <= '1';
	HEX1_DP <= '1';
	HEX2_DP <= '1';
	HEX3_DP <= '1';
	
end;
