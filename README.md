# ⚡ GoodWe Smart Charger

## Sprint 2 – Prova de Conceito Funcional

### Challenge FIAP 2026 – GoodWe

---

## Sobre o Projeto

O **GoodWe Smart Charger** é uma proposta de infraestrutura inteligente para recarga de veículos elétricos, desenvolvida como parte do Challenge FIAP em parceria com a GoodWe.

A solução busca transformar estacionamentos comerciais, condomínios e centros empresariais em ambientes energeticamente eficientes, utilizando fontes renováveis e sistemas inteligentes de gerenciamento de energia.

A partir da proposta apresentada na Sprint 1, esta Sprint 2 apresenta uma **prova de conceito funcional**, validando tecnicamente a viabilidade do núcleo da solução: a distribuição inteligente de energia entre múltiplos carregadores.

---

## Problema

Com o crescimento acelerado da mobilidade elétrica, surgem novos desafios relacionados à infraestrutura de recarga:

- Sobrecarga da rede elétrica devido ao carregamento simultâneo de diversos veículos;
- Má distribuição da potência disponível;
- Baixo aproveitamento da energia proveniente de sistemas fotovoltaicos;
- Dependência excessiva da rede pública de energia;
- Elevados custos operacionais;
- Ausência de mecanismos inteligentes para priorização energética.

Esses fatores reduzem a eficiência dos sistemas de recarga e comprometem sua sustentabilidade econômica e ambiental.

---

## Solução Proposta

O GoodWe Smart Charger propõe uma plataforma inteligente capaz de:

- Monitorar continuamente a disponibilidade energética;
- Priorizar o uso de energia solar;
- Utilizar bancos de baterias como fonte complementar;
- Acionar a rede elétrica apenas quando necessário;
- Distribuir dinamicamente a potência entre os carregadores;
- Evitar situações de sobrecarga;
- Maximizar a eficiência energética do sistema.

Nesta Sprint, foi implementada uma prova de conceito da lógica de distribuição inteligente denominada **Energy Brain**.

---

## 🎯 Objetivos

### Objetivo Geral

Demonstrar a viabilidade técnica inicial do GoodWe Smart Charger por meio de um protótipo funcional simulado.

### Objetivos Específicos

- Desenvolver uma prova de conceito operacional;
- Simular diferentes cenários de disponibilidade energética;
- Demonstrar a priorização de fontes renováveis;
- Evidenciar mecanismos de prevenção de sobrecarga;
- Validar a lógica central da solução proposta.

---

## 🧪 Prova de Conceito Desenvolvida

A prova de conceito foi implementada utilizando o simulador Wokwi e um ESP32 como controlador central.

O sistema recebe entradas simuladas referentes à:

- Energia solar disponível;
- Demanda total de carregamento dos veículos.

A partir desses dados, o Energy Brain realiza automaticamente a distribuição da energia disponível.

### Ordem de Prioridade Energética

1. Energia Solar;
2. Banco de Baterias;
3. Rede Elétrica.

Quando a demanda excede a capacidade disponível, o sistema limita a distribuição de potência, evitando sobrecargas na infraestrutura.

---

## Arquitetura da Solução

### Arquitetura Conceitual

```text
Painéis Solares
       ↓
Banco de Baterias
       ↓
Gateway IoT
       ↓
Energy Brain (IA)
       ↓
Nuvem GoodWe
       ↓
Carregadores Inteligentes
       ↓
Aplicativo do Usuário
```

### Arquitetura da Prova de Conceito

```text
Potenciômetro (Energia Solar)
              ↓
Potenciômetro (Demanda)
              ↓
ESP32 – Energy Brain
              ↓
Distribuição Inteligente
              ↓
LEDs Representando Carregadores
              ↓
Painel Administrativo (Serial Monitor)
```

---

## Funcionamento do Protótipo

O sistema executa continuamente as seguintes etapas:

1. Leitura da energia solar simulada;
2. Leitura da demanda energética simulada;
3. Cálculo da potência disponível;
4. Priorização das fontes renováveis;
5. Distribuição da energia entre os carregadores;
6. Acionamento dos indicadores visuais;
7. Exibição das informações em tempo real.

---

## Dados Simulados

Exemplo de cenários operacionais obtidos durante a simulação:

| Energia Solar | Bateria | Rede | Demanda | Status |
|---|---:|---:|---:|---|
| 25 kW | 0 kW | 5 kW | 30 kW | Operação Normal |
| 15 kW | 20 kW | 10 kW | 45 kW | Operação Normal |
| 5 kW | 20 kW | 30 kW | 55 kW | Operação Normal |
| 0 kW | 20 kW | 30 kW | 65 kW | Sobrecarga Evitada |

---

## Distribuição Energética

Um exemplo de distribuição energética durante a operação do sistema é apresentado abaixo:

| Fonte Energética | Energia Utilizada |
|---|---:|
| Energia Solar | 25 kW |
| Banco de Baterias | 15 kW |
| Rede Elétrica | 10 kW |

Nesse cenário, aproximadamente **80% da energia utilizada é proveniente de fontes renováveis e armazenamento local**, reduzindo significativamente a dependência da rede elétrica convencional.

---

## Sustentabilidade e Eficiência Energética ♻️

A sustentabilidade é um dos pilares centrais da proposta.

A solução promove:

- Maior aproveitamento da energia gerada por sistemas fotovoltaicos;
- Redução da dependência da rede elétrica convencional;
- Utilização inteligente dos bancos de baterias;
- Redução de desperdícios energéticos;
- Mitigação indireta das emissões de carbono;
- Uso racional dos recursos energéticos disponíveis.

Além disso, o uso do ESP32 demonstra a aplicação de dispositivos eletrônicos de baixo consumo energético em sistemas inteligentes de gestão.

---

## Relação com Energias Renováveis

A proposta está diretamente alinhada aos princípios estudados na disciplina ao integrar fontes renováveis ao processo de carregamento de veículos elétricos.

O modelo desenvolvido evidencia que sistemas inteligentes podem:

- Maximizar o aproveitamento da energia solar;
- Reduzir impactos ambientais;
- Melhorar a estabilidade da infraestrutura elétrica;
- Incentivar a expansão sustentável da mobilidade elétrica.

---

## 🧠 Energy Brain

O Energy Brain representa a camada decisória do sistema.

Na prova de conceito, suas funções incluem:

- Monitoramento energético;
- Priorização das fontes disponíveis;
- Distribuição dinâmica da potência;
- Prevenção de sobrecargas.

Em futuras evoluções, essa camada poderá incorporar algoritmos avançados de Inteligência Artificial para previsão de demanda, análise de padrões de consumo e otimização preditiva da infraestrutura energética.

---

## Tecnologias Utilizadas

- ESP32;
- Wokwi Simulator;
- Linguagem C++;
- Internet das Coisas (IoT);
- Sistemas Fotovoltaicos;
- Gestão Inteligente de Energia;
- Mobilidade Elétrica;
- Computação em Nuvem (arquitetura conceitual);
- Inteligência Artificial (arquitetura conceitual).

---

## Como Executar

1. Abrir o projeto no simulador Wokwi;
2. Iniciar a simulação;
3. Ajustar o potenciômetro responsável pela energia solar disponível;
4. Ajustar o potenciômetro responsável pela demanda energética;
5. Observar os LEDs correspondentes aos carregadores ativos;
6. Monitorar as informações exibidas no Serial Monitor;
7. Analisar os diferentes cenários de distribuição energética.

---

## Resultados Obtidos

A prova de conceito demonstrou que a lógica central do GoodWe Smart Charger é tecnicamente viável.

Os testes simulados evidenciaram que o sistema consegue:

- Distribuir energia de maneira inteligente;
- Priorizar fontes renováveis;
- Utilizar baterias como suporte energético;
- Acionar a rede elétrica apenas quando necessário;
- Evitar situações de sobrecarga;
- Adaptar-se dinamicamente às variações de demanda.

Esses resultados indicam o potencial da solução para aplicações futuras em ambientes comerciais e corporativos.

---

## Trabalhos Futuros

Como evolução do projeto, propõe-se:

- Desenvolvimento do aplicativo móvel funcional;
- Integração com serviços em nuvem;
- Implementação de autenticação de usuários;
- Cobrança automatizada das sessões de recarga;
- Aplicação de modelos de Inteligência Artificial preditiva;
- Integração com carregadores e inversores reais da GoodWe.

---

## 👥 Equipe

- RM 572431 – Mateus de Oliveira Fernandes Neves
- RM 571285 – Pedro Soares de Souza
- RM 569272 – Olavo Dadario Vianna Barreto
- RM 570797 – Angela Sousa Takezawa
- RM 569496 – Paulo Henrique Lira Bilac de Araujo

---

## Licença

Projeto desenvolvido exclusivamente para fins acadêmicos e educacionais, como parte do Challenge FIAP 2026 em parceria com a GoodWe.
