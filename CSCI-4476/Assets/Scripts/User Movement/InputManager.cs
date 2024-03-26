using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class InputManager : MonoBehaviour
{
    public static InputManager instance;
    static FirstPerson actions;
    public static Action<Vector2> movement;
    public static Action<Vector2> mouseLook;
    public static Action interactAction;
    public static Action stopInteractAction;

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
        actions.InGame.Movement.performed += InvokeMovemt;
        actions.InGame.Movement.canceled += InvokeMovemt;
        actions.InGame.MouseLook.performed += InvokeMouseLook;
        actions.InGame.MouseLook.canceled += InvokeMouseLook;
        actions.InGame.Interact.performed += InvokeInteract;
        actions.InGame.Interact.canceled += InvokeStopInteract;
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

    void OnDisable(){
        actions.InGame.Movement.performed -= InvokeMovemt;
        actions.InGame.Movement.canceled -= InvokeMovemt;
        actions.InGame.MouseLook.performed -= InvokeMouseLook;
        actions.InGame.MouseLook.canceled -= InvokeMouseLook;
        actions.InGame.Interact.performed -= InvokeInteract;
        actions.InGame.Interact.canceled -= InvokeStopInteract;
    }
}
