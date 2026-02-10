<p align="center"></p>

## Table of Contents
- [Souls Like Combat Mechanics](#souls-like-combat-project)
  - [Project Overview](#souls-project-overview)
  - [Gameplay](#souls-gameplay)
  - [Project Details](#souls-project-details)
  - [Core Systems](#souls-core-systems)
  - [Combat Features](#souls-combat-features)
  - [Bow and Arrow](#souls-bow-and-arrow)
  - [Modular Projectile System](#souls-modular-projectile-system)
  - [Gameplay Abilities (GAS)](#souls-gameplay-abilities-gas)
  - [UI Feedback](#souls-ui-feedback)
 


## Souls Project Details

| Platform | Engine | Tech | Team Size | Roles |
| --- | --- | --- | --- | --- |
| PC | Unreal Engine 5 | C++, Blueprints, GAS | Duo | Gameplay Programmer (Combat/Systems) |

---

## Souls Collaboration
Duo project built with a VFX artist.  
I handled GAS architecture, combat systems, AI combat hooks, and UI logic. The VFX artist delivered Niagara effects for attacks, abilities, hits, and elemental feedback to improve readability and impact.

---

## Souls Core Systems
- GAS based abilities with stamina costs, cooldowns, gameplay effects, and tags.
- Modular damage pipeline (hit reactions, stagger, death handling).
- Movement support for combat and traversal (vaulting, mantling, grounded locomotion).

---

## Souls Combat Features
- Multiple melee weapons with reusable combat framework.
- Light attacks and heavy combo chains with combo UI feedback.
- Charged attacks with scaling.
- Block/guard with stamina drain and guard break.
- Dodge/roll with stamina cost and i-frame window.
- Enemy AI combat loop (attack selection, reactions, pressure).

---

## Souls Bow and Arrow
- Draw, aim, release loop integrated with GAS.
- Target practice setup for tuning aim and timing.
- Data driven arrow types (fire, freeze, poison ready for expansion).

---

## Souls Modular Projectile System
- GAS driven projectile abilities (spawn, travel, impact, apply effects).
- Optional lock style auto targeting.
- Multiple projectile types supported via reusable projectile core.

---

## Souls Gameplay Abilities (GAS)
- Health and stamina attribute sets.
- Dash ability (GAS, cost, cooldown, prediction safe flow).
- Damage, hit reaction, stagger, and status effects as Gameplay Effects.
- Extensible ability framework for future skills.

---

## Souls UI Feedback
- Health and stamina bars bound to attributes.
- Cooldown UI hooks for abilities.
- Hit feedback indicators.
- Combo counter / combat state UI hooks.


