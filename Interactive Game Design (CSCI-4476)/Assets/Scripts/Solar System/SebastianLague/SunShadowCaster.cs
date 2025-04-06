using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/*
    Source: Sebastian Lague
    https://github.com/SebLague/Solar-System/tree/Episode_01
    Accessed 3 May 2024
*/

public class SunShadowCaster : MonoBehaviour
{
    Transform track;

    void Start () {
        track = Camera.main.transform;
    }

    void LateUpdate () {
        transform.LookAt (track.position);
    }
}
