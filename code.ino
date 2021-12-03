
const int led_r = 7;
const int led_y = 4;
const int led_g = 1;
const int led_pedestre = 8;

const int botao_pedestre = 12;
bool para = true;

unsigned long current_time = 0;

// muda o estado dos leds

void led(uint8_t vermelho, uint8_t amarelo, uint8_t verde)
{
  digitalWrite(led_r, vermelho);
  digitalWrite(led_y, amarelo);
  digitalWrite(led_g, verde);
  digitalWrite(led_pedestre, vermelho);
}

void vermelho()
{
  led(HIGH, LOW, LOW);
  delay(10000);
}

void amarelo()
{
  led(LOW, HIGH, LOW);
  delay(5000);
}


// o codigo para rodando o while, sempre atualizando millis(),
// comparando com o current_time pego no inicio, antes do while.
// ou seja, millis sempre cresce, current_time nao.
// entao quando se passam 10 segundos a condicao se torna falsa.

void verde()
{
  current_time = millis();
  while((millis() - current_time) < 10000)
  {
    led(LOW, LOW, HIGH);
    
  	if(digitalRead(botao_pedestre))
  	{
  		led(LOW, HIGH, LOW);
  		delay(2000);
      	break;
  	}
  }
}

void setup()
{
  pinMode(led_r, OUTPUT);
  pinMode(led_y, OUTPUT);
  pinMode(led_g, OUTPUT);
  pinMode(led_pedestre, OUTPUT);
  pinMode(botao_pedestre, INPUT);
}

void loop()
{
  vermelho(); 
  amarelo();
  verde();
}
