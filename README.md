<h2 align="center">Gameplay Mechanics and Abilities using GAS (Multiplayer Integration)</h2>
<p align="center">Built using C++, Blueprints and Unreal Engine 5</p>

---

## Table of Contents
- [Overview](#overview)
- [Gameplay Demo](#gameplay-demo)
- [Project Details](#project-details)
- [Core Systems](#core-systems)
- [Gameplay Abilities](#gameplay-abilities)
  - [Dash Ability](#dash-ability)


---

## Overview

This project is a third person multiplayer gameplay framework built around Unreal Engine's Gameplay Ability System.

The goal was to implement scalable, replicated gameplay abilities with clean C++ architecture and Blueprint friendly extension points.

The system focuses on:
- Server authoritative execution
- Data driven ability design
- Modular and maintainable gameplay code

---

## Gameplay Demo

Click the image below to watch the demo:

<p align="center">
  <a href="https://www.youtube.com/watch?v=21OzrVktwzA" target="_blank" rel="noopener noreferrer">
    <img src="https://github.com/user-attachments/assets/4eddc091-8649-4187-a79c-8fa5acec11e9" alt="Gameplay Demo" width="600"/>
  </a>
</p>


## Project Details

| Platform | Engine | Duration | Team Size | Role |
|----------|--------|----------|-----------|------|
| PC | Unreal Engine 5/C++ | Present | Duo | AI/Gameplay Programmer |

---

## Core Systems

### Gameplay Ability System Integration

- AbilitySystemComponent implemented in C++
- Custom AttributeSet for health, stamina, and combat stats
- Gameplay Tags for state management and ability gating
- Gameplay Effects for cost, cooldown, and attribute modification
- Delegates for UI update binding

### Character Architecture

- Ability System attached via PlayerState for multiplayer stability
- Clean separation between Character, PlayerState, and Ability logic
- RepNotify usage for syncing gameplay state across clients
- Blueprint exposed APIs for fast iteration

---

## Gameplay Abilities

### Dash Ability

- Implemented using Gameplay Ability in C++
- Root motion driven movement
- Cooldown and stamina cost handled via Gameplay Effects
- Activation restricted using Gameplay Tags
- Server authoritative execution with client prediction
- Multicast cosmetic feedback support

---




