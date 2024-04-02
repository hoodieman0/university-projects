using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class InputManager : MonoBehaviour
{
    public  static  InputManager        instance;
    public  static  FirstPerson         actions;
    public  static  Action<Vector2>     movement;
    public  static  Action<Vector2>     mouseLook;
    public  static  Action              interactAction;
    public  static  Action              stopInteractAction;
    public  static  Action<int>         inventoryAction;
    public  static  Action              dropAction;
    // public static Action num1Action;
    // public static Action num2Action;
    // public static Action num3Action;

    void Awake(){
        if (!instance){
            instance = this;
            actions = new();
            actions.Enable();
        }
        else {
            Destroy(gameObject);
        }
    }

    void OnEnable(){
        // Movement
        actions.InGame.Movement.performed += InvokeMovemt;
        actions.InGame.Movement.canceled += InvokeMovemt;

        // Mouse Look
        actions.InGame.MouseLook.performed += InvokeMouseLook;
        actions.InGame.MouseLook.canceled += InvokeMouseLook;

        // Interaction
        actions.InGame.Interact.performed += InvokeInteract;
        actions.InGame.Interact.canceled += InvokeStopInteract;

        // Inventory
        actions.InGame.Inventory1.performed += InvokeSlot1;
        actions.InGame.Inventory2.performed += InvokeSlot2;
        actions.InGame.Inventory3.performed += InvokeSlot3;
        actions.InGame.Drop.performed += InvokeDrop;

    }

    void InvokeMovemt(InputAction.CallbackContext ctx){
        movement?.Invoke(ctx.ReadValue<Vector2>());
    }

    void InvokeMouseLook(InputAction.CallbackContext ctx){
        mouseLook?.Invoke(ctx.ReadValue<Vector2>());
    }

    void InvokeInteract(InputAction.CallbackContext ctx){
        interactAction?.Invoke();
    }

    void InvokeStopInteract(InputAction.CallbackContext ctx){
        stopInteractAction?.Invoke();
    }

    void InvokeSlot1(InputAction.CallbackContext ctx){
        inventoryAction?.Invoke(0);
    }

    void InvokeSlot2(InputAction.CallbackContext ctx){
        inventoryAction?.Invoke(1);
    }

    void InvokeSlot3(InputAction.CallbackContext ctx){
        inventoryAction?.Invoke(2);
    }

    void InvokeDrop(InputAction.CallbackContext ctx){
        dropAction?.Invoke();
    }

    void OnDisable(){
        // Movement
        actions.InGame.Movement.performed -= InvokeMovemt;
        actions.InGame.Movement.canceled -= InvokeMovemt;

        // Mouse look
        actions.InGame.MouseLook.performed -= InvokeMouseLook;
        actions.InGame.MouseLook.canceled -= InvokeMouseLook;

        // Interaction
        actions.InGame.Interact.performed -= InvokeInteract;
        actions.InGame.Interact.canceled -= InvokeStopInteract;

        // Inventory
        actions.InGame.Inventory1.performed -= InvokeSlot1;
        actions.InGame.Inventory2.performed -= InvokeSlot2;
        actions.InGame.Inventory3.performed -= InvokeSlot3;
        actions.InGame.Drop.performed -= InvokeDrop;
    }
}
