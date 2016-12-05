
#include "sys/alt_stdio.h"
#include "system.h"
#include "io.h"

#include "src/Defs.h"
#include "src/Controller.h"
#include "src/Selector.h"
#include "src/Display.h"

/**
 * Switchs:
 * 0: Cafe
 * 1: Cafe com leite
 * 2: Mocacchino
 * 3: Acucar
 * 4: Tamanho do copo
 * 5: Nivel da agua
 * 6: Temperatura da agua
 */

// Instancias dos componentes
Controller controller;
Display display;
Selector selector;

// Estado atual da maquina de estados
states state;

int main()
{
	coffeTypes selectedCoffe = T_NONE;
	bool withSugar = false;
	int cupSize = 0;
	int waterTemp = 0;
	int waterLevel = 0;

	state = st_SELECT;

	while(1)
	{
		// Sinalizacao do reversatorio de agua
		waterLevel = controller.getWaterLevel();
		waterTemp = controller.getWaterTemp();
		display.setLedWaterLevel(waterLevel);
		display.setLedWaterTemp(waterTemp);

		// Atualiza os LEDs
		selectedCoffe = selector.getSelectedCoffe();
		display.setLedCoffe(selectedCoffe == T_COFFE ? 1 : 0);
		display.setLedCoffeMilk(selectedCoffe == T_COFFEMILK ? 1 : 0);
		display.setLedMocacchino(selectedCoffe == T_MOCACCHINO ? 1 : 0);

		cupSize = selector.getCupSize();
		display.setLedCopo(cupSize);

		display.setLedSugar(selector.isWithSugar());


		// Maquina de estados iluminati
		switch(state)
		{
			case st_SELECT:
				alt_printf("Estou na selecao\n");

				if(selector.isPrepararPressed())
				{

					// Caso nao selecionou nenhum cafe, fica no st_SELECT
					if(selectedCoffe == T_NONE)
					{
						state = st_SELECT;
					}
					else
					{
						withSugar = selector.isWithSugar();
						state = st_CHECK_REFILL;
					}
				}

			break;

			case st_CHECK_REFILL:
				alt_printf("Estou na check refill\n");
				if(!controller.needToResupply(selectedCoffe, withSugar))
				{
					state = st_MAKE;
				}
				else
				{
					state = st_NO_SUPPLIES;
				}

			break;

			case st_NO_SUPPLIES:
				alt_printf("Estou na st_NO_SUPPLIES\n");
				display.setLedRepor(1);
				if(selector.isReporPressed())
				{
					controller.refill(selectedCoffe, withSugar);
					state = st_CHECK_REFILL;
					display.setLedRepor(0);
				}

			break;

			case st_MAKE:
				alt_printf("Estou na st_MAKE\n");

				display.showWait();

				// Inicia o preparo do cafe
				cupSize = selector.getCupSize();
				controller.make(selectedCoffe, withSugar, cupSize);

				display.showDone();
				usleep(5000000);

				state = st_RESET;

			break;

			case st_RESET:
				alt_printf("Estou na st_RESET\n");
				// Reseta os LEDs
				display.clearLeds();

				// Reseta os displays
				display.clearDisplays();

				state = st_SELECT;
			break;
		}
	}

  return 0;
}
