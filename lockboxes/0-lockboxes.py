#!/usr/bin/python3
"""
Verifica si se pueden desbloquear todos los cajones de una lista dada.
"""


def canUnlockAll(boxes):
    """
    Verifica si se pueden desbloquear todos los cajones de una lista dada.
    """
    # Revisa si los cajones y sub cajones son una lista
    if type(boxes) is not list or not all(type(box) is list for box in boxes):
        return False
    # Revisa si la lista está vacía
    if len(boxes) == 0:
        return False
    # Revisa si solo existe un cajón
    if len(boxes) == 1:
        return True
    # Revisa si el primer cajón está vacío
    if not boxes[0] and len(boxes) > 1:
        return False
    # Crea un diccionario con todos los cajones bloqueados
    unlock = {k: False for k in range(len(boxes))}
    # Desbloquea el primer cajón
    unlock[0] = True
    # Lista con las llaves del primer cajón
    keys = [key for key in boxes[0]]
    # Proceso de desbloqueo de los cajones
    while keys:
        new_k = []
        for key in keys:
            # Revisa si la llave está en el diccionario
            # y si el cajón está bloqueado
            if key in unlock.keys() and unlock[key] is False:
                # Agrega las llaves del cajón a la lista
                new_k += boxes[key]
                # Desbloquea el cajón
                unlock[key] = True
        # Si todos los cajones están desbloqueados, devuelve True
        if all(unlock.values()) and len(unlock) == len(boxes):
            return True
        # Cambia las llaves por las nuevas llaves para revisar
        keys = new_k
    return False
