# Trens - Sistema de Simulação de Trens

Sistema de simulação de trens desenvolvido em Qt/C++.

## Descrição

Aplicação que simula o movimento de múltiplos trens em um sistema de trilhos. O sistema utiliza semáforos binários para garantir a sincronização e evitar colisões entre os trens.

## Componentes

### Servidor (`server/`)
- Gerencia múltiplos trens simultaneamente
- Implementa sincronização usando semáforos (QSemaphore)
- Recebe comandos de controle via TCP

### Cliente (`client/`)
- Interface gráfica para controle dos trens
- Conecta-se ao servidor via TCP
- Permite ligar/desligar trens
- Ajusta a velocidade dos trens

## Funcionalidades

- Controle de múltiplos trens
- Ajuste de velocidade
- Sincronização automática
