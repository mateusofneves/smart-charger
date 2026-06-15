# GoodWe Smart Charger

> Plataforma inteligente de gerenciamento energético para recarga de veículos elétricos utilizando energia solar, baterias e rede elétrica de forma otimizada.

![Status](https://img.shields.io/badge/Status-Prova%20de%20Conceito-success)
![ESP32](https://img.shields.io/badge/ESP32-IoT-blue)
![Wokwi](https://img.shields.io/badge/Wokwi-Simulation-orange)
![FIAP](https://img.shields.io/badge/FIAP-Challenge-red)

---

# Sobre o Projeto

O **GoodWe Smart Charger** é uma solução desenvolvida para o Challenge FIAP 2026 em parceria com a GoodWe.

O projeto propõe uma infraestrutura inteligente de recarga para veículos elétricos capaz de gerenciar a distribuição de energia entre diferentes fontes energéticas, priorizando fontes renováveis e reduzindo a dependência da rede elétrica convencional.

A proposta evolui o conceito tradicional de carregadores para um sistema inteligente de gerenciamento energético, capaz de tomar decisões em tempo real sobre qual fonte de energia utilizar para atender à demanda de carregamento.

---

# Problema

Com o crescimento acelerado da mobilidade elétrica, surgem desafios importantes relacionados à infraestrutura energética:

- Sobrecarga da rede elétrica;
- Crescimento do consumo simultâneo de energia;
- Baixo aproveitamento da geração solar;
- Dependência excessiva da concessionária;
- Custos operacionais elevados;
- Falta de inteligência na distribuição energética.

Sem mecanismos inteligentes de controle, o aumento da demanda pode comprometer a estabilidade da infraestrutura elétrica.

---

# Solução

O GoodWe Smart Charger implementa um módulo central denominado **Energy Brain**, responsável por:

- Monitorar a energia disponível;
- Priorizar energia solar;
- Utilizar baterias como fonte complementar;
- Acionar a rede elétrica apenas quando necessário;
- Distribuir energia de forma inteligente;
- Evitar situações de sobrecarga;
- Maximizar a eficiência energética.

---

# Energy Brain

O Energy Brain representa a camada de tomada de decisão do sistema.

Sua lógica segue a seguinte prioridade:

```text
1º Energia Solar
        ↓
2º Banco de Baterias
        ↓
3º Rede Elétrica
```

Essa abordagem reduz custos energéticos e aumenta o aproveitamento das fontes renováveis.

---

# Arquitetura Conceitual

```text
Painéis Solares
       ↓
Banco de Baterias
       ↓
Gateway IoT
       ↓
Energy Brain
       ↓
Nuvem GoodWe
       ↓
Carregadores Inteligentes
       ↓
Aplicativo Mobile
```

---

# Prova de Conceito Desenvolvida

Para validar a proposta foi construída uma simulação funcional utilizando ESP32 e Wokwi.

O sistema recebe entradas simuladas referentes à geração solar e à demanda energética dos carregadores.

Com base nesses dados, o Energy Brain calcula automaticamente a melhor estratégia de distribuição de energia.

---

# Arquitetura do Protótipo

```text
Potenciômetro (Energia Solar)
               ↓
Potenciômetro (Demanda)
               ↓
ESP32
               ↓
Energy Brain
               ↓
LCD I2C
               ↓
LEDs Indicadores
               ↓
Serial Monitor
```

---

# Tecnologias Utilizadas

- ESP32
- Linguagem C++
- Wokwi Simulator
- IoT (Internet of Things)
- Gestão Inteligente de Energia
- Sistemas Fotovoltaicos
- Mobilidade Elétrica
- Arquitetura em Nuvem (conceitual)
- Inteligência Artificial (conceitual)

---

# Componentes Utilizados

| Componente | Função |
|------------|---------|
| ESP32 | Controlador principal |
| Potenciômetro 1 | Simulação da geração solar |
| Potenciômetro 2 | Simulação da demanda energética |
| LCD 16x2 I2C | Exibição das informações |
| LED Verde | Energia solar em uso |
| LED Amarelo | Banco de baterias em uso |
| LED Azul | Rede elétrica em uso |
| Push Button | Alternância de telas |

---

# Ligações do Circuito

| Componente | ESP32 |
|------------|--------|
| Potenciômetro Solar (SIG) | GPIO 34 |
| Potenciômetro Demanda (SIG) | GPIO 35 |
| Botão | GPIO 18 |
| LED Amarelo | GPIO 25 |
| LED Azul | GPIO 26 |
| LED Verde | GPIO 27 |
| LCD SDA | GPIO 21 |
| LCD SCL | GPIO 22 |

### Alimentação

| Componente | Ligação |
|------------|----------|
| Potenciômetros | 3.3V e GND |
| LCD I2C | 5V e GND |
| LEDs | Resistor 220Ω → GND |

---

# Funcionamento

O sistema executa continuamente os seguintes processos:

1. Leitura da energia solar disponível;
2. Leitura da demanda energética;
3. Cálculo da potência necessária;
4. Distribuição inteligente das fontes;
5. Atualização dos indicadores visuais;
6. Monitoramento em tempo real.

---

# Indicadores do Sistema

| LED | Significado |
|------|-------------|
| 🟢 Verde | Energia solar utilizada |
| 🟡 Amarelo | Banco de baterias utilizado |
| 🔵 Azul | Rede elétrica utilizada |

Os LEDs podem permanecer acesos simultaneamente, indicando a utilização combinada de diferentes fontes energéticas.

---

# Interface do Usuário

## Tela 1

```text
Solar: XX kW
Dem: YY kW
```

Exibe a energia solar disponível e a demanda atual.

---

## Tela 2

```text
Fonte: Solar
Operacao OK
```

ou

```text
Fonte: Solar+Bateria
Operacao OK
```

ou

```text
Fonte: Sol+Bat+Rede
Operacao OK
```

ou

```text
Fonte: Sol+Bat+Rede
Sobrecarga!
```

---

# Cenários Testados

## Cenário 1 — Energia Solar Suficiente

```text
Solar = 30 kW
Demanda = 10 kW
```

Resultado:

- Utilização exclusiva da energia solar;
- Operação normal.

---

## Cenário 2 — Complementação por Bateria

```text
Solar = 10 kW
Demanda = 25 kW
```

Resultado:

- Utilização da bateria como suporte;
- Operação normal.

---

## Cenário 3 — Complementação por Rede

```text
Solar = 5 kW
Demanda = 50 kW
```

Resultado:

- Utilização das três fontes energéticas;
- Operação normal.

---

## Cenário 4 — Limite de Potência

```text
Solar = 0 kW
Demanda = 60 kW
```

Resultado:

- Sistema utiliza todos os recursos disponíveis;
- Limitação inteligente da potência;
- Sobrecarga evitada.

---

# Sustentabilidade

A proposta busca maximizar o aproveitamento de energia renovável através de:

- Energia solar fotovoltaica;
- Utilização estratégica de baterias;
- Redução do consumo da rede elétrica;
- Menor desperdício energético;
- Maior eficiência operacional.

---

# Resultados

A prova de conceito demonstrou que a lógica central do Energy Brain é capaz de:

- Priorizar fontes renováveis;
- Distribuir energia de forma inteligente;
- Adaptar-se dinamicamente à demanda;
- Utilizar múltiplas fontes energéticas;
- Evitar sobrecargas da infraestrutura.

Os testes realizados validaram a viabilidade técnica da proposta para aplicações em estacionamentos, condomínios e ambientes corporativos.

---

# 🚀 Próximos Passos

- Aplicativo mobile funcional;
- Dashboard administrativo em nuvem;
- Integração com MQTT;
- Integração com APIs da GoodWe;
- Sistema de autenticação de usuários;
- Cobrança automatizada;
- Algoritmos preditivos com IA;
- Integração com carregadores reais.

---

# 👥 Equipe

**Challenge FIAP 2026 – GoodWe**

- RM 572431 – Mateus de Oliveira Fernandes Neves
- RM 571285 – Pedro Soares de Souza
- RM 569272 – Olavo Dadario Vianna Barreto
- RM 570797 – Angela Sousa Takezawa
- RM 569496 – Paulo Henrique Lira Bilac de Araujo

---

# Licença

Projeto desenvolvido para fins acadêmicos e educacionais como parte do Challenge FIAP 2026 em parceria com a GoodWe.

---

## Competências Demonstradas

- Internet das Coisas (IoT)
- Sistemas Embarcados
- ESP32
- Linguagem C++
- Energia Solar
- Gestão Inteligente de Energia
- Eficiência Energética
- Mobilidade Elétrica
- Wokwi
- Smart Charging
- Smart Grid
- Prototipagem de Soluções Tecnológicas
