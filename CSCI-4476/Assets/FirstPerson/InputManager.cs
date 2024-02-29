using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.InputSystem;

public class InputManager : MonoBehaviour
{
    public static InputManager instance;
    static FirstPerson actions;
    public static Action<Vector2> moveAction;
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

    public void OnEnable(){
        actions.InGame.Movement.performed += InvokeMovement;
        actions.InGame.Movement.canceled += InvokeMovement;
        actions.InGame.MouseLook.performed += InvokeMouseLook;
        actions.InGame.MouseLook.canceled += InvokeMouseLook;
        actions.InGame.Interact.performed += InvokeInteract;
        actions.InGame.Interact.canceled += StopInteract;
    }

    void InvokeMovement(InputAction.CallbackContext ctx){
        moveAction?.Invoke(ctx.ReadValue<Vector2>());
    }

    void InvokeMouseLook(InputAction.CallbackContext ctx){
        mouseLook?.Invoke(ctx.ReadValue<Vector2>());
    }

    void InvokeInteract(InputAction.CallbackContext ctx){
        interactAction?.Invoke();
    }
    void StopInteract(InputAction.CallbackContext ctx){
        stopInteractAction?.Invoke();
    }

    public void OnDisable(){
        actions.InGame.Movement.performed -= InvokeMovement;
        actions.InGame.Movement.canceled -= InvokeMovement;
        actions.InGame.MouseLook.performed -= InvokeMouseLook;
        actions.InGame.MouseLook.canceled -= InvokeMouseLook;
    }
}
