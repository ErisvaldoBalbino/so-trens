# Trens

Simulação de trens sincronizados com semáforos, com cliente e servidor via TCP

Atividade de **Sistemas Operacionais** (SO) — IFRN.

## Stack

![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white) ![Qt](https://img.shields.io/badge/Qt-41CD52?style=for-the-badge&logo=qt&logoColor=white)

## Como rodar

Abra o `trens.pro` no Qt Creator (Qt 6) e rode primeiro o `server` e depois o `client`.

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

## Demonstração
https://github.com/user-attachments/assets/9758cb42-6221-40c1-abee-80c43a77da47
